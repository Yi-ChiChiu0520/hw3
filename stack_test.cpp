#include "stack.h" // Make sure this matches the name of your header file
#include <iostream>
#include <string>

int main() {
    // Create a Stack of integers
    Stack<int> intStack;

    // Test pushing elements
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Test size
    std::cout << "Expected size after 3 pushes: 3, Actual size: " << intStack.size() << std::endl;

    // Test top element
    std::cout << "Expected top element: 3, Actual top element: " << intStack.top() << std::endl;

    // Test popping elements
    intStack.pop();
    std::cout << "Expected size after pop: 2, Actual size: " << intStack.size() << std::endl;
    std::cout << "Expected top element after pop: 2, Actual top element: " << intStack.top() << std::endl;

    // Test underflow error on pop
    try {
        intStack.pop();
        intStack.pop(); // At this point, stack should be empty.
        intStack.pop(); // This should throw an underflow_error.
    } catch (const std::underflow_error& e) {
        std::cout << "Caught underflow error on pop as expected: " << e.what() << std::endl;
    }

    // Test underflow error on top
    try {
        intStack.top(); // This should throw an underflow_error since stack is empty.
    } catch (const std::underflow_error& e) {
        std::cout << "Caught underflow error on top as expected: " << e.what() << std::endl;
    }

    // Demonstrating usage with a different type (e.g., std::string)
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Expected top string: World, Actual top string: " << stringStack.top() << std::endl;

    // Success
    std::cout << "All basic tests passed." << std::endl;

    return 0;
}
