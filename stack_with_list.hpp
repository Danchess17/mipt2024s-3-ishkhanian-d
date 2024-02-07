#include <iostream>

template <typename T>
struct Node {
    T element;
    Node* next;
    Node(T elem) : element(elem), next(nullptr) {}
    Node(T elem, Node* node) : element(elem), next(node) {}
};

template <typename T>
class StackWithList {
    private:
        Node<T>* head;
        int length;

    public:
        StackWithList() : head(nullptr), length(0) {}

        bool empty() const {
            return (head == nullptr);
        }

        void push(const T& elem) {
            head = new Node<T>(elem, head);
            ++length;
        }

        T top() const {
            if (head == nullptr) {
                std::cout << "Error: taking top element from empty stack..." << std::endl;
                exit(1);
            }
            return head->element;
        }

        T pop() {
            if (head == nullptr) {
                std::cout << "Error: popping top element from empty stack..." << std::endl;
                exit(1);
            }

            T elem = head->element;
            Node<T>* next = head->next;
            delete head;
            head = next;
            --length;
            return elem;
        }

        int size() const {
            return length;
        }

        void display() const {
            Node<T>* temp = head;
            while (temp != nullptr) {
                std::cout << temp->element << " -> ";
                temp = temp->next;
            }
            std::cout << std::endl;
        };
};
