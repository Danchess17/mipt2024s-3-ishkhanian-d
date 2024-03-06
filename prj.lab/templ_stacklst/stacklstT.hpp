#ifndef TEMPL_STACKLST_HPP
#define TEMPL_STACKLST_HPP

#include <iostream>

template<typename T>
class StackLstT {
public:
  StackLstT() : head(nullptr), length(0) {}

  StackLstT(const StackLstT& st) : head(nullptr), length(st.length) {
      if (st.head == nullptr) return;
      head = new Node(st.head->element);
      Node* copy = head;
      Node* temp = st.head;
      while (temp->next != nullptr) {
        temp = temp->next;
        copy->next = new Node(temp->element);
        copy = copy->next;
      }
  }

  StackLstT(StackLstT&& st) noexcept : head(nullptr), length(0) {
      std::swap(head, st.head);
      std::swap(length, st.length);
  }

  ~StackLstT() = default;

  StackLstT& operator=(const StackLstT& st) {
      StackLstT stack(st);
      std::swap(head, stack.head);
      std::swap(length, stack.length);
      return *this;
  }

  StackLstT& operator=(StackLstT&& st) noexcept {
      std::swap(head, st.head);
      std::swap(length, st.length);
      return *this;
  }

  const T& Top() const {
      if (head == nullptr) {
        std::cout << "Error: taking top element from empty stack..." << std::endl;
        exit(1);
      }
      return head->element;
  }

  T& Top() {
    if (head == nullptr) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return head->element;
  }

  void Push(const T& elem) {
      head = new Node(elem, head);
      ++length;
  }

  void Pop() noexcept {
      if (head == nullptr) {
        std::cout << "Error: popping top element from empty stack..."
                  << std::endl;
        exit(1);
      }
      Node* next = head->next;
      delete head;
      head = next;
      --length;
  }

  bool IsEmpty() const noexcept { return (head == nullptr); }

  int Size() const noexcept { return length; }

  void Clear() noexcept {
        while (length != 0) {
            Pop();
        }
  }
private:
  struct Node {
    T element;
    Node* next;
    Node(const T& elem) : element(elem), next(nullptr) {}
    Node(const T& elem, Node *node) 
    : element(elem), next(node) {}
  };
  Node* head;
  int length;
};

#endif
