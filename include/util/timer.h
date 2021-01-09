//
// Created by Chow on 2021/1/9.
//

#ifndef CPP11_TIMER_H
#define CPP11_TIMER_H

#include <ctime>

class timer {
public:

    timer() = default;

    void setStartTime() {
        clock_gettime(CLOCK_MONOTONIC, &start); // suggest CLOCK_MONOTONIC
    }

    void setEndTime() {
        clock_gettime(CLOCK_MONOTONIC, &end);
    }

    timespec getStartTime() {
        return start;
    }

    timespec getEndTime() {
        return end;
    }

    long getDiffTimeSec() {
        return end.tv_sec - start.tv_sec;
    }

    long getDiffTimeMilli() {
        return (end.tv_sec - start.tv_sec) * 1000L +
               (end.tv_nsec - start.tv_nsec) / 1000000L;
    }

    long getDiffTimeMicro() {
        return (end.tv_sec - start.tv_sec) * 1000000L +
               (end.tv_nsec - start.tv_nsec) / 1000L;
    }

    long getDiffTimeNano() {
        return (end.tv_sec - start.tv_sec) * 1000000000L +
               (end.tv_nsec - start.tv_nsec);
    }

private:
    struct timespec start = {};
    struct timespec end = {};
};

#endif //CPP11_TIMER_H
