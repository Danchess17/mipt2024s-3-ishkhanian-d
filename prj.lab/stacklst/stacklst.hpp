#ifndef STACKLST_HPP
#define STACKLST_HPP

class StackLst {
public:
  StackLst();
  StackLst(const StackLst& st);
  StackLst(StackLst&& st) noexcept;
  ~StackLst() = default;
  StackLst& operator=(const StackLst& st);
  StackLst& operator=(StackLst&& st) noexcept;
  const float& Top() const;
  void Push(const float& elem);
  void Pop() noexcept;
  bool IsEmpty() const noexcept;
  int Size() const noexcept;
  void Clear() noexcept;
private:
  struct Node {
    float element;
    Node* next;
    Node(const float& elem);
    Node(const float& elem, Node* node);
  };
  Node* head;
  int length;
};

#endif
