#include <string>
#include <vector>
#include <iostream>
#include <chrono>

#include "rocksdb/db.h"
#include "util/timer.h"

const size_t kKeyCount = 1024;
const size_t kBlockSize = 1024 * 1024;

int main(int argc, char* argv[]) {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./db2", &db);
    std::cout << "rocksdb open status: " << status.ok() << std::endl;

    std::string key1 = "key1";
    std::string key2;
    std::string value1 = "value111111111111";
    std::string value2;

    Timer timer;
    timer.setStartTime();

    status = db->Put(rocksdb::WriteOptions(), key1, value1);
    status = db->Get(rocksdb::ReadOptions(), key1, &value2);
    std::cout << "value1: " << value1 << ", value2: " << value2 << std::endl;

    timer.setEndTime();

    db->Close();

    return 0;
}

