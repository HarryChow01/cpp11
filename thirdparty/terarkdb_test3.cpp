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

std::string kDBPath = "./data2";

int main() {
    // open DB
    Options options;
    options.create_if_missing = true;
    DB* db;
    Status s;

    std::vector<std::string> cfNames;
    s = rocksdb::DB::ListColumnFamilies(DBOptions(), kDBPath, &cfNames);
    std::cout << "cfNames.size(): " << cfNames.size() << std::endl;
    for (const auto& cfName : cfNames) {
        std::cout << "cfName: " << cfName << std::endl;
    }


    // open DB with two column families
    std::vector<ColumnFamilyDescriptor> column_families;
    // have to open default column family
    column_families.emplace_back(kDefaultColumnFamilyName, ColumnFamilyOptions());
    // open the new one, too
    column_families.emplace_back("new_cf", ColumnFamilyOptions());
    std::vector<ColumnFamilyHandle*> handles;
    s = DB::Open(DBOptions(), kDBPath, column_families, &handles, &db);
    assert(s.ok());

    s = db->Put(WriteOptions(), handles[0], Slice("a1"), Slice("a1"));
    s = db->Put(WriteOptions(), handles[1], Slice("b1"), Slice("b1"));

    delete db;

    return 0;
}