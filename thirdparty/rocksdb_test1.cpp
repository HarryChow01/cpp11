//
// Created by Chow on 2020/12/27
//

#include <string>
#include <vector>
#include <iostream>
#include <chrono>

#include "rocksdb/db.h"

const size_t kKeyCount = 1024;
const size_t kBlockSize = 1024 * 1024;

int main(int argc, char* argv[]) {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./testdb", &db);
    std::cout << "rocksdb open status: " << status.ok() << std::endl;

    // std::string sKey("key1");
    // std::string sValue("value1");

    rocksdb::WriteBatch batch;
    rocksdb::WriteOptions writeOptions;

    for (int i = 0; i < kKeyCount; ++i) {
        std::string key = std::to_string(i + 1);
        std::string value(kBlockSize, 'a');
        batch.Put(key, value);
    }

    auto beginTime = std::chrono::high_resolution_clock::now();
    db->Write(writeOptions, &batch);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime1 = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);
    std::cout << "batch.Data().size(): " << batch.Data().size() << std::endl;
    std::cout << "db->Write time in ms: " << elapsedTime1.count() << std::endl;

    db->Close();

    return 0;
}

