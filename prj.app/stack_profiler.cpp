#include <stackarr/stackarr.hpp>
#include <stacklst/stacklst.hpp>

#include <iostream>
#include <chrono>

using cl = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;

void Test1() {
    std::cout << "Test 1" << std::endl;
    int n = 1000000;
    auto start_array = cl::now();
    for (int i = 0; i < n; ++i) { 
        StackArr stack_array;
    } 
    auto end_array = cl::now();
    double array_init_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array init time taken by program is : " << array_init_time << " sec" << std::endl;

    auto start_list = cl::now(); 
    for (int i = 0; i < n; ++i) { 
        StackLst stack_list;
    } 
    auto end_list = cl::now();
    double list_init_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List init time taken by program is : " << list_init_time << " sec" << std::endl;

    if (list_init_time < array_init_time) {
        std::cout << "Stack-List constructor is " << 
        array_init_time / list_init_time << " faster";
    } else {
        std::cout << "Stack-Array constructor is " << 
        list_init_time / array_init_time << " faster";
    } 
    std::cout << std::endl;
}

void Test2() {
    std::cout << "Test 2" << std::endl;
    int n = 1000000;

    StackArr stack_array;
    auto start_array = cl::now();
    for (int i = 0; i < n; ++i) { 
        stack_array.Push(5.0);
    } 
    for (int i = 0; i < n; ++i) { 
        stack_array.Pop();
    } 
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array push-pop time taken by program is : " << array_time << " sec" << std::endl;

    StackLst stack_list;
    auto start_list = cl::now(); 
    for (int i = 0; i < n; ++i) { 
        stack_list.Push(5.0);
    } 
    for (int i = 0; i < n; ++i) { 
        stack_list.Pop();
    } 
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List push-pop time taken by program is : " << list_time << " sec" << std::endl;

    if (list_time < array_time) {
        std::cout << "Stack-List push-pop is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array push-pop is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;
}

void Test3() {
    std::cout << "Test 3" << std::endl;
    int n = 1000000;

    StackArr stack_array;
    for (int i = 0; i < n; ++i) { 
        stack_array.Push(5.0);
    }

    auto start_array = cl::now();
    for (int i = 0; i < n; ++i) { 
        stack_array.Top();
        stack_array.Pop();
    } 
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array top-pop time taken by program is : " << array_time << " sec" << std::endl;

    StackLst stack_list;
    for (int i = 0; i < n; ++i) { 
        stack_list.Push(5.0);
    }

    auto start_list = cl::now(); 
    for (int i = 0; i < n; ++i) { 
        stack_list.Top();
        stack_list.Pop();
    } 
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List top-pop time taken by program is : " << list_time << " sec" << std::endl;

    if (list_time < array_time) {
        std::cout << "Stack-List top-pop is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array top-pop is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;  
}

void Test4() {
    std::cout << "Test 4" << std::endl;
    int n = 100000000;

    auto start_array = cl::now();
    StackArr stack_array;
    for (int i = 0; i < n; ++i) {
        int r = rand() % 5;
        if (r == 0) stack_array.IsEmpty();
        else if (r == 1) stack_array.Push(5.0);
        else if (r == 2 && !stack_array.IsEmpty()) stack_array.Pop();
        else if (r == 3 && !stack_array.IsEmpty()) stack_array.Top();
        else if (r == 4) stack_array.Size();
        else continue;
    }
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array chaotic time taken by program is : " << array_time << " sec" << std::endl;

    auto start_list = cl::now(); 
    StackLst stack_list;
    for (int i = 0; i < n; ++i) {
        int r = rand() % 5;
        if (r == 0) stack_list.IsEmpty();
        else if (r == 1) stack_list.Push(5.0);
        else if (r == 2 && !stack_list.IsEmpty()) stack_list.Pop();
        else if (r == 3 && !stack_list.IsEmpty()) stack_list.Top();
        else if (r == 4) stack_list.Size();
        else continue;
    }
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List chaotic time taken by program is : " << list_time << " sec" << std::endl;

    if (list_time < array_time) {
        std::cout << "Stack-List chaotic is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array chaotic is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;  
}

void Test5() {
    std::cout << "Test 5" << std::endl;
    int n = 1000000;

    StackArr stack_array;
    auto start_array = cl::now();
    for (int i = 0; i < n; ++i) { 
        stack_array.Push(5.0);
    } 
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array push-only time taken by program is : " << array_time << " sec" << std::endl;

    StackLst stack_list;
    auto start_list = cl::now(); 
    for (int i = 0; i < n; ++i) { 
        stack_list.Push(5.0);
    } 
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List push-only time taken by program is : " << list_time << " sec" << std::endl;

    if (list_time < array_time) {
        std::cout << "Stack-List push is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array push is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;  
}

void Test6() {
    std::cout << "Test 6" << std::endl;
    int n = 1000000;

    StackArr stack_array;
    for (int i = 0; i < n; ++i) { 
        stack_array.Push(5.0);
    }
    auto start_array = cl::now();
    for (int i = 0; i < n; ++i) {
        stack_array.Pop();
    }
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array pop-only time taken by program is : " << array_time << " sec" << std::endl;

    StackLst stack_list;
    for (int i = 0; i < n; ++i) { 
        stack_list.Push(5.0);
    }
    auto start_list = cl::now();
    for (int i = 0; i < n; ++i) {
        stack_list.Pop();
    }
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List pop-only time taken by program is : " << list_time << " sec" << std::endl;

    if (list_time < array_time) {
        std::cout << "Stack-List pop is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array pop is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;  
}

void Test7() {
    std::cout << "Test 7" << std::endl;
    int n = 1000000;

    auto start_array = cl::now();
    StackArr stack_array;
    for (int i = 0; i < n; ++i) { 
        stack_array.Push(5.0);
    } 
    for (int i = 0; i < n; ++i) { 
        stack_array.Pop();
    } 
    auto end_array = cl::now();
    double array_time = std::chrono::duration_cast<ns>(end_array - start_array).count() * 1e-9;
    std::cout << "Array init-push-pop time taken by program is : " << array_time << " sec" << std::endl;

    auto start_list = cl::now(); 
    StackLst stack_list;
    for (int i = 0; i < n; ++i) { 
        stack_list.Push(5.0);
    } 
    for (int i = 0; i < n; ++i) { 
        stack_list.Pop();
    } 
    auto end_list = cl::now();
    double list_time = std::chrono::duration_cast<ns>(end_list - start_list).count() * 1e-9;
    std::cout << "List init-push-pop time taken by program is : " << list_time << " sec" << std::endl;

     if (list_time < array_time) {
        std::cout << "Stack-List init-push-pop is " 
        << array_time / list_time << " faster";
    } else {
        std::cout << "Stack-Array init-push-pop is " 
        << list_time / array_time << " faster";
    } 
    std::cout << std::endl;  
}


int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}
