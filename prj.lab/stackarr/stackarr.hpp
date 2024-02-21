#ifndef STACKARR_HPP
#define STACKARR_HPP

class StackArr {
public:
  StackArr(int cap = 8);
  StackArr(const StackArr& st);
  StackArr(StackArr&& st) noexcept;
  ~StackArr();
  StackArr& operator=(const StackArr& st);
  StackArr& operator=(StackArr&& st) noexcept;
  const float& Top() const;
  void Push(const float& elem);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  int Size() const noexcept;
  void Clear() noexcept;
private:
  float* stack;
  int length;
  int capacity;
};

#endif