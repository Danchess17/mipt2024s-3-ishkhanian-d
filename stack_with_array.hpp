#include <iostream>

template <typename T>
class StackWithArray {
    private:
        T* stack;
        int capacity;  
        int length;

    public:
        StackWithArray(int cap = 8) : length(0), capacity(cap) {
            stack = new T[cap];
        }

        ~StackWithArray() {
            delete [] stack;
        }

        bool empty() const {
            return (length == 0);
        }

        void push(const T& elem) {
            if (length == capacity) {
                capacity *= 2;
                T* newstack = new T[capacity];
                for (int i = 0; i < length; ++i) {
                    newstack[i] = stack[i];
                }
                delete [] stack;
                stack = newstack;
            }
            stack[length] = elem;
            length++;
        }

        T top() const {
            if (length == 0) {
                std::cout << "Error: taking top element from empty stack..." << std::endl;
                exit(1);
            }
            return stack[length - 1];
        }

        T pop() {
            if (length == 0) {
                std::cout << "Error: popping top element from empty stack..." << std::endl;
                exit(1);
            }
            T temp = stack[length - 1]; 
            length--; 
            if (length < capacity / 4) { 
                capacity /= 2; 
                T* newstack = new T[capacity];
                for (int i = 0; i < length; ++i) { 
                    newstack[i] = stack[i]; 
                }
                delete [] stack;
                stack = newstack;
            }
            return temp;
        }

        int size() const {
            return length;
        }

        void display() const {
            for (int i = 0; i < length; ++i) {
                std::cout << stack[length - i - 1] << " -> ";
            }
            std::cout << std::endl;
        };
};
