#include <stacklst/stacklst.hpp>

#include <iostream>
//#include <algorithm>
//#include <stdexcept>

StackLst::Node::Node(const float &elem) : element(elem), next(nullptr) {}

StackLst::Node::Node(const float &elem, StackLst::Node *node) 
: element(elem), next(node) {}


StackLst::StackLst() : head(nullptr), length(0) {}

StackLst::StackLst(const StackLst& st) : head(nullptr), length(st.length) {
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


StackLst::StackLst(StackLst&& st) noexcept : head(nullptr), length(0) {
    std::swap(head, st.head);
    std::swap(length, st.length);
}

StackLst& StackLst::operator=(const StackLst& st) {
    StackLst stack(st);
    std::swap(head, stack.head);
    std::swap(length, stack.length);
    return *this;
  }

StackLst& StackLst::operator=(StackLst&& st) noexcept {
    std::swap(head, st.head);
    std::swap(length, st.length);
    return *this;
}

const float& StackLst::Top() const {
    if (head == nullptr) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return head->element;
}

void StackLst::Push(const float& elem) {
    head = new Node(elem, head);
    ++length;
}

void StackLst::Pop() noexcept {
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

bool StackLst::IsEmpty() const noexcept { return (head == nullptr); }

int StackLst::Size() const noexcept { return length; }

void StackLst::Clear() noexcept {
      while (length != 0) {
          Pop();
      }
}

