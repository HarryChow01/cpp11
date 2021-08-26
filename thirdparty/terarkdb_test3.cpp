// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#include "rocksdb/db.h"
#include "rocksdb/slice.h"
#include "rocksdb/options.h"

using namespace rocksdb;

std::string kDBPath = "./data3";

void getCfNames();

void test1() {
    Options options;
    options.create_if_missing = true;
    DB* db;

    // 如果目录下面有列族，则出错
    Status s = DB::Open(options, kDBPath, &db);
    assert(s.ok());

    std::vector<std::string> cfNames;
    s = rocksdb::DB::ListColumnFamilies(DBOptions(), kDBPath, &cfNames);
    std::cout << "cfNames.size(): " << cfNames.size() << std::endl;
    for (const auto& cfName : cfNames) {
        std::cout << "cfName: " << cfName << std::endl;
    }

    // create column family
    ColumnFamilyHandle* cf;
    s = db->CreateColumnFamily(ColumnFamilyOptions(), "cf_0", &cf);
    assert(s.ok());
    // close DB
    s = db->DestroyColumnFamilyHandle(cf);
    assert(s.ok());

    // create column family
    s = db->CreateColumnFamily(ColumnFamilyOptions(), "cf_1", &cf);
    assert(s.ok());
    // close DB
    s = db->DestroyColumnFamilyHandle(cf);
    assert(s.ok());
    delete db;

    // open DB with two column families
    std::vector<ColumnFamilyDescriptor> column_families;
    // have to open default column family
    column_families.emplace_back(kDefaultColumnFamilyName, ColumnFamilyOptions());
    column_families.emplace_back("cf_0", ColumnFamilyOptions());
    column_families.emplace_back("cf_1", ColumnFamilyOptions());
    std::vector<ColumnFamilyHandle*> handles;
    s = DB::Open(DBOptions(), kDBPath, column_families, &handles, &db);
    assert(s.ok());
    std::cout << "handles.size(): " << handles.size() << std::endl;

    s = db->Put(WriteOptions(), handles[0], Slice("a1"), Slice("a1"));
    s = db->Put(WriteOptions(), handles[1], Slice("b1"), Slice("b1"));

    db->Flush(FlushOptions(), handles[0]);
    db->Flush(FlushOptions(), handles[1]);

    delete db;
}

/* 测试创建列族：
 * 第1步，创建一个空的db（默认创建一个default列族）
 * 第2步，添加几个列族然后destroy掉 */
void test2() {
    Options options;
    options.create_if_missing = true;
    DB* db;

    // 如果目录下面有列族，则出错
    Status s = DB::Open(options, kDBPath, &db);
    assert(s.ok());

    getCfNames();

    // create column family
    ColumnFamilyHandle* cf;
    s = db->CreateColumnFamily(ColumnFamilyOptions(), "cf_0", &cf);
    assert(s.ok());
    // close DB
    s = db->DestroyColumnFamilyHandle(cf);
    assert(s.ok());

    // create column family
    s = db->CreateColumnFamily(ColumnFamilyOptions(), "cf_1", &cf);
    assert(s.ok());
    // close DB
    s = db->DestroyColumnFamilyHandle(cf);
    assert(s.ok());
    delete db;

    getCfNames();
}

void test3() {
    Options options;
    options.create_if_missing = true;
    DB* db;
    std::vector<ColumnFamilyHandle*> handles;


    std::vector<std::string> column_family_names;
    Status status = rocksdb::DB::ListColumnFamilies(options, kDBPath, &column_family_names);
    std::vector<rocksdb::ColumnFamilyDescriptor> column_families;

    for (size_t i = 0; i != column_family_names.size(); i++) {
        column_families.emplace_back(column_family_names[i], rocksdb::ColumnFamilyOptions(options));
    }

    status = rocksdb::DB::Open(options, kDBPath, column_families, &handles, &db);

    rocksdb::Iterator* it = db->NewIterator(rocksdb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        std::cout << it->key().ToString() << ": " << it->value().ToString() << std::endl;
    }

}


bool diff(const std::string& dbPath1, const std::string& dbPath2) {
    // todo
    return true;
}


void getCfNames() {
    std::vector<std::string> cfNames;
    Status s = rocksdb::DB::ListColumnFamilies(DBOptions(), kDBPath, &cfNames);
    std::cout << "cfNames.size(): " << cfNames.size() << std::endl;
    for (const auto& cfName : cfNames) {
        std::cout << "cfName: " << cfName << std::endl;
    }
}

void getCfNames2(const std::string& dbPath) {
    std::vector<std::string> cfNames;
    Status s = rocksdb::DB::ListColumnFamilies(DBOptions(), dbPath, &cfNames);
    std::cout << "cfNames.size(): " << cfNames.size() << std::endl;
    for (const auto& cfName : cfNames) {
        std::cout << "cfName: " << cfName << std::endl;
    }
}

int main() {
    const std::string dbPath = "/data/rocksdb/tf_base_ctr_3";
    getCfNames2(dbPath);

    return 0;
}

