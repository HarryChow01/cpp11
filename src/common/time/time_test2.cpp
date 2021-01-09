//
// Created by Chow on 2021/1/9.
//

#include <iostream>
#include "util/timer.h"

int main() {

    const size_t kCount = 1024 * 1024 * 1024;
    timer t1;
    timespec tp1 = t1.getStartTime();
    std::cout << "tp1.tv_sec: " << tp1.tv_sec << ", tp1.tv_nsec: " << tp1.tv_nsec << std::endl;
    tp1 = t1.getEndTime();
    std::cout << "tp1.tv_sec: " << tp1.tv_sec << ", tp1.tv_nsec: " << tp1.tv_nsec << std::endl;

    t1.setStartTime();
    size_t count = 0;
    for (size_t i = 0; i < kCount; ++i) {
        ++count;
    }
    t1.setEndTime();

    std::cout << "diffTime in second: " << t1.getDiffTimeSec() << std::endl;
    std::cout << "diffTime in millisecond: " << t1.getDiffTimeMilli() << std::endl;
    std::cout << "diffTime in microsecond: " << t1.getDiffTimeMicro() << std::endl;
    std::cout << "diffTime in nanosecond: " << t1.getDiffTimeNano() << std::endl;

    return 0;
}
