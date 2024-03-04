#include "heap.h"
#include <iostream>
#include <string>
#include <functional>

int main() {
    // Test min-heap with integers
    Heap<int> minHeap;
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    minHeap.push(1);
    minHeap.push(3);

    std::cout << "Min-Heap (integers): ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << "\n";

    // Test max-heap with integers, using std::greater functor
    Heap<int, std::greater<int>> maxHeap;
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(8);
    maxHeap.push(1);
    maxHeap.push(3);

    std::cout << "Max-Heap (integers): ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << "\n";

    // Test min-heap with strings
    Heap<std::string> minHeapStr;
    minHeapStr.push("banana");
    minHeapStr.push("apple");
    minHeapStr.push("cherry");
    minHeapStr.push("date");

    std::cout << "Min-Heap (strings): ";
    while (!minHeapStr.empty()) {
        std::cout << minHeapStr.top() << " ";
        minHeapStr.pop();
    }
    std::cout << "\n";

    // Test max-heap with strings, using std::greater functor
    Heap<std::string, std::greater<std::string>> maxHeapStr;
    maxHeapStr.push("banana");
    maxHeapStr.push("apple");
    maxHeapStr.push("cherry");
    maxHeapStr.push("date");

    std::cout << "Max-Heap (strings): ";
    while (!maxHeapStr.empty()) {
        std::cout << maxHeapStr.top() << " ";
        maxHeapStr.pop();
    }
    std::cout << "\n";

    return 0;
}
