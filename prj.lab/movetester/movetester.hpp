#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>

using cl = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;
using stats = std::pair<double, double>; 

template <bool IsTest>
class MoveTester {
 public:
    MoveTester() = default;
    ~MoveTester() = default;
    MoveTester(MoveTester&& other) {
        if (!IsTest) { std::vector<float> another(v); }
    };
    MoveTester(const MoveTester& other) {
        if (IsTest) { std::vector<float> another(v); }
    };
 private:
    std::vector<float> v{std::vector<float>(10000000, 5.0)};
};

stats MeanVar(const std::vector<double>& profiler) {
    double n = profiler.size();
    double mean = 0;
    double squared = 0;
    for (double val : profiler) {
        mean += val;
        squared += val * val;
    }
    mean /= n;
    squared /= n;
    double var = std::sqrt(squared - mean * mean);
    return {mean, var};
}

template <typename T>
std::pair<stats, stats> MoveTest(const T& obj) {
    if (!std::is_move_constructible<T>::value || !std::is_copy_constructible<T>::value) {
        throw std::runtime_error("T must be move-constructible and copy-constructible");
    }

    std::vector<double> move_profiler, copy_profiler;

    for (int i = 0; i < 1000000; ++i) {
        auto start_copy = cl::now();
        T obj_copy(obj);
        auto end_copy = cl::now();
        auto time_copy = 
            std::chrono::duration_cast<ns>(end_copy - start_copy).count();
        copy_profiler.push_back(time_copy);

        auto start_move = cl::now();
        T obj_move(std::move(obj_copy));
        auto end_move = cl::now();
        auto time_move =
            std::chrono::duration_cast<ns>(end_move - start_move).count();
        move_profiler.push_back(time_move);
    }
    return {MeanVar(move_profiler), MeanVar(copy_profiler)};
}

void Print(const std::pair<stats, stats>& res) {
  std::cout << "Move: " << res.first.first << " +- " << res.first.second << std::endl;
  std::cout << "Copy: " << res.second.first << " +- " << res.second.second << std::endl;
}