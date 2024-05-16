#include <chrono>
#include <string>
#include <fstream>
#include <iostream>

using cl = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;

struct FileTimer {
    FileTimer(const char* fileName = "") : name(fileName), time(0.0), cnt(0) {}
    const char* name;
    double time;
    unsigned long long cnt;
};

class Ancor {
 public:
    Ancor(int count, bool flag = true) : count(count), flag(flag) {}
    Ancor(int count, const char* name = "", bool flag = true)
    : count(count), name(name), flag(flag) {
        if (flag) {
            data[count].name = name;
            data[count].cnt = 0;
            data[count].time = 0.0;
            ptr = &data[count];
        }
    }

    FileTimer* GetPtr() { return ptr; }

    void WriteToFile(const std::string& file_name) {
        if (flag) {
            std::fstream file(file_name, std::fstream::out);
            file << "Operation, Time (s), Number of iterations\n";
            for (int i = 0; i < count; ++i) {
                file << data[i].name << ",\t" << data[i].time << ",\t"
                    << data[i].cnt << '\n';
            }
        }
    }


    static FileTimer* data;
 private:
    int count;
    const char* name;
    bool flag;
    FileTimer* ptr;
};

class Timer {
 public:
    Timer(FileTimer* fileTimer, bool flag) :   
        file_timer_(fileTimer), flag(flag), start(cl::now()) {}
    ~Timer() {
        if (flag) {
            auto end = cl::now();
            file_timer_->time +=
                std::chrono::duration_cast<ns>(end - start).count() * 1e-9;
            file_timer_->cnt += 1;
        }
    }

 private:
    FileTimer* file_timer_;
    bool flag;
    std::chrono::time_point<cl> start;
};