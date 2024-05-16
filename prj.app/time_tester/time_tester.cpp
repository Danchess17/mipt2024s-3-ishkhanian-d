#include <timer/timer.hpp>
#include <stackarr/stackarr.hpp>

bool flag = true;


#define profiler_mode true

StackArr stack;

void push() {
    #ifdef profiler_mode
    static Ancor ancor(__COUNTER__, __FUNCTION__, flag);
    Timer timer(ancor.GetPtr(), flag);
    #endif
    stack.Push(5.0);
}

void pop() {
    #ifdef profiler_mode
    static Ancor ancor(__COUNTER__, __FUNCTION__, flag);
    Timer timer(ancor.GetPtr(), flag);
    #endif
    stack.Pop();
}

FileTimer a[__COUNTER__];
FileTimer* Ancor::data = a;

int main() {
    #if profiler_mode
    std::cout << "With profiler!" << std::endl;
    #else
    std::cout << "Without profiler!" << std::endl;
    #endif

    auto push_start = cl::now();
    for (int i = 0; i < 100000; ++i) {
        push();
    }
    auto push_end = cl::now();
    auto push_time = std::chrono::duration_cast<ns>(push_end - push_start).count();
    if (!flag) {
        printf("Push,\t%f,\t100000\n", push_time * 1e-9);
    }

    auto pop_start = cl::now();
    for (int i = 0; i < 100000; ++i) {
        pop();
    }
    auto pop_end = cl::now();
    auto pop_time = std::chrono::duration_cast<ns>(pop_end - pop_start).count();
    if (!flag) {
        printf("Pop,\t%f,\t100000\n", pop_time * 1e-9);
    }

    Ancor ancor(__COUNTER__ - 1, flag);
    ancor.WriteToFile("log.csv");
    return 0;
}
