#include <stackarr/stackarr.hpp>
#include <iostream>

StackArr::StackArr(int cap) : length(0), capacity(cap) {
    stack = new float[cap]; 
}

StackArr::StackArr(const StackArr& st) : 
length(st.length), capacity(st.capacity) {
    stack = new float[capacity];
    for (int i = 0; i < length; ++i) {
        stack[i] = st.stack[i];
    }
}

StackArr::StackArr(StackArr&& st) noexcept
      : length(0), capacity(0), stack(nullptr) {
    std::swap(length, st.length);
    std::swap(capacity, st.capacity);
    std::swap(stack, st.stack);
}

StackArr::~StackArr() { delete[] stack; }

StackArr& StackArr::operator=(const StackArr& st) {
    if (this != &st) {
      delete[] stack;
      length = st.length;
      capacity = st.capacity;
      stack = new float[capacity];
      for (int i = 0; i < length; ++i) {
        stack[i] = st.stack[i];
      }
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& st) noexcept {
    std::swap(length, st.length);
    std::swap(capacity, st.capacity);
    std::swap(stack, st.stack);
    return *this;
}

const float& StackArr::Top() const {
    if (length == 0) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return stack[length - 1];
}

float& StackArr::Top() {
    if (length == 0) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return stack[length - 1];
}

void StackArr::Push(const float& elem) {
    if (length == capacity) {
      capacity *= 2;
      float* newstack = new float[capacity];
      for (int i = 0; i < length; ++i) {
        newstack[i] = stack[i];
      }
      delete[] stack;
      stack = newstack;
    }
    stack[length] = elem;
    length++;
}

void StackArr::Pop() noexcept {
    if (length == 0) {
      std::cout << "Error: popping top element from empty stack..."
                << std::endl;
      exit(1);
    }
    length--;
    if (length < capacity / 4) {
      capacity /= 2;
      float* newstack = new float[capacity];
      for (int i = 0; i < length; ++i) {
        newstack[i] = stack[i];
      }
      delete[] stack;
      stack = newstack;
    }
  }

bool StackArr::IsEmpty() const noexcept { return (length == 0); }

int StackArr::Size() const noexcept { return length; }

void StackArr::Clear() noexcept {
      while (length != 0) {
          Pop();
      }
}

