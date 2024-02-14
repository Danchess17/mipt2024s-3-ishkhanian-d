#include <iostream>

template <typename T>
struct Node {
  T element;
  Node* next;
  Node(const T& elem) : element(elem), next(nullptr) {}
  Node(const T& elem, Node* node) : element(elem), next(node) {}
};

template <typename T>
class StackWithList {
 private:
  Node<T>* head;
  int length;

 public:
  StackWithList() : head(nullptr), length(0) {}

  StackWithList(const StackWithList<T>& s) : head(nullptr), length(0) {
      Node<T>* temp = s.head;
      while (temp != nullptr) {
          push(temp->element);
          temp = temp->next;
      }
  }


  ~StackWithList() = default;

  StackWithList& operator=(const StackWithList<T>& s) { // ok
       StackWithList stack(s); // todo
       std::swap(head, stack.head);
       std::swap(length, stack.length);
       return *this;
  }

  StackWithList(StackWithList<T>&& s) noexcept : head(nullptr), length(0) { // ok
      std::swap(head, s.head);
      std::swap(length, s.length);
  }

  StackWithList& operator=(StackWithList<T>&& s) noexcept { // ok 
      std::swap(head, s.head);
      std::swap(length, s.length);
      return *this;
  }

  void push(const T& elem) {
    head = new Node<T>(elem, head);
    ++length;
  }

  void pop() noexcept {
    if (head == nullptr) {
      std::cout << "Error: popping top element from empty stack..."
                << std::endl;
      exit(1);
    }

    Node<T>* next = head->next;
    delete head;
    head = next;
    --length;
  }

  bool empty() const noexcept { return (head == nullptr); }

  const T& top() const {
    if (head == nullptr) {
      std::cout << "Error: taking top element from empty stack..." << std::endl;
      exit(1);
    }
    return head->element;
  }

  int size() const noexcept { return length; }

  void display() const {
    Node<T>* temp = head;
    while (temp != nullptr) {
      std::cout << temp->element << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  };
};
