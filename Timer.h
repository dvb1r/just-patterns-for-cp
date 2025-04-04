//
// Created by dvb1r on 9/26/2024.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> timePoint;
    size_t value;
    void start() { timePoint = std::chrono::steady_clock::now(); }
    ~Timer() {
        auto curr = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curr - timePoint);
        value = elapsed.count();
        std::cerr << "\nruntime: " << value << "ms";
    }
    size_t operator()() const {
        return value;
    }
    explicit Timer() { start(); }
};

#endif //TIMER_H
