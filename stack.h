#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : private std::vector<T> // Private inheritance
{
public:
    Stack() {} // Constructor
    ~Stack() {} // Destructor

    // Check if the stack is empty
    bool empty() const {
        return std::vector<T>::empty();
    }

    // Get the size of the stack
    size_t size() const {
        return std::vector<T>::size();
    }

    // Add an item to the top of the stack
    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

    // Remove the top item from the stack
    void pop() {
        if (empty()) {
            throw std::underflow_error("Empty stack");
        }
        std::vector<T>::pop_back();
    }

    // Get the top item of the stack
    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Empty stack");
        }
        return std::vector<T>::back();
    }
};

#endif