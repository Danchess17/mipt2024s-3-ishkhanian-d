#include <iostream>

template <typename T>
class StackWithArray {
 private:
  T* stack;
  int capacity;
  int length;

 public:
  StackWithArray(int cap = 8) : length(0), capacity(cap) { stack = new T[cap]; }

  StackWithArray(const StackWithArray<T>& s)
      : length(s.length), capacity(s.capacity) {
    stack = new T[capacity];
    for (int i = 0; i < length; ++i) {
      stack[i] = s.stack[i];
    }
  }

  ~StackWithArray() { delete[] stack; }

  StackWithArray& operator=(const StackWithArray<T>& s) {
    if (this != &s) {
      delete[] stack;
      length = s.length;
      capacity = s.capacity;
      stack = new T[capacity];
      for (int i = 0; i < length; ++i) {
        stack[i] = s.stack[i];
      }
    }
    return *this;
  }

  StackWithArray(StackWithArray<T>&& s) noexcept
      : length(0), capacity(0), stack(nullptr) {
    std::swap(length, s.length);
    std::swap(capacity, s.capacity);
    std::swap(stack, s.stack);
  }

  StackWithArray& operator=(StackWithArray<T>&& s) noexcept {
    std::swap(length, s.length);
    std::swap(capacity, s.capacity);
    std::swap(stack, s.stack);
    return *this;
  }

  void push(const T& elem) {
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

  void pop() noexcept {
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

  bool empty() const noexcept { return (length == 0); }

  const T& top() const {
    if (length == 0) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return stack[length - 1];
  }

  int size() const noexcept { return length; }

  void display() const {
    for (int i = 0; i < length; ++i) {
      std::cout << stack[length - i - 1] << " ";
    }
    std::cout << std::endl;
  };
};
