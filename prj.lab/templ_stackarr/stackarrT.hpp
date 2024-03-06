#ifndef TEMPL_STACKARR_HPP
#define TEMPL_STACKARR_HPP

#include <iostream>

template <typename T>
class StackArrT {
public:
  StackArrT(int cap = 8) : length(0), capacity(cap) {
      stack = new T[cap]; 
  }

  StackArrT(const StackArrT& st) : 
  length(st.length), capacity(st.capacity) {
      stack = new T[capacity];
      for (int i = 0; i < length; ++i) {
          stack[i] = st.stack[i];
      }
  }

  StackArrT(StackArrT&& st) noexcept
        : length(0), capacity(0), stack(nullptr) {
      std::swap(length, st.length);
      std::swap(capacity, st.capacity);
      std::swap(stack, st.stack);
  }

  ~StackArrT() { delete[] stack; }

  StackArrT& operator=(const StackArrT& st) {
      if (this != &st) {
        delete[] stack;
        length = st.length;
        capacity = st.capacity;
        stack = new T[capacity];
        for (int i = 0; i < length; ++i) {
          stack[i] = st.stack[i];
        }
      }
      return *this;
  }

  StackArrT& operator=(StackArrT&& st) noexcept {
      std::swap(length, st.length);
      std::swap(capacity, st.capacity);
      std::swap(stack, st.stack);
      return *this;
  }

  const T& Top() const {
      if (length == 0) {
        std::cout << "Error: taking top element from empty stack..." << std::endl;
        exit(1);
      }
      return stack[length - 1];
  }

  T& Top() {
    if (length == 0) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return stack[length - 1];
  }

  void Push(const T& elem) {
      if (length == capacity) {
        capacity *= 2;
        T* newstack = new T[capacity];
        for (int i = 0; i < length; ++i) {
          newstack[i] = stack[i];
        }
        delete[] stack;
        stack = newstack;
      }
      stack[length] = elem;
      length++;
  }

  void Pop() noexcept {
      if (length == 0) {
        std::cout << "Error: popping top element from empty stack..."
                  << std::endl;
        exit(1);
      }
      length--;
      if (length < capacity / 4) {
        capacity /= 2;
        T* newstack = new T[capacity];
        for (int i = 0; i < length; ++i) {
          newstack[i] = stack[i];
        }
        delete[] stack;
        stack = newstack;
      }
    }

  bool IsEmpty() const noexcept { return (length == 0); }

  int Size() const noexcept { return length; }

  void Clear() noexcept {
        while (length != 0) {
            Pop();
        }
  }
private:
  T* stack;
  int length;
  int capacity;
};

#endif