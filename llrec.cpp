#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void append(Node*& list, Node* node) {
    if (list == nullptr) {
        list = node;
    } else {
        Node* current = list;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }
    node->next = nullptr; // Ensure the appended node's next is nullptr.
}

void llpivotRecursive(Node*& head, Node*& smaller, Node*& larger, int pivot, Node*& lastSmaller, Node*& lastLarger) {
    if (head == nullptr) return; // Base case: end of the list

    Node* nextNode = head->next; // Save the next node
    head->next = nullptr; // Detach the current node from the list

    if (head->val <= pivot) {
        if (smaller == nullptr) {
            smaller = head; // Initialize smaller list with the current node
            lastSmaller = head;
        } else {
            lastSmaller->next = head; // Append to the end of the smaller list
            lastSmaller = head;
        }
    } else {
        if (larger == nullptr) {
            larger = head; // Initialize larger list with the current node
            lastLarger = head;
        } else {
            lastLarger->next = head; // Append to the end of the larger list
            lastLarger = head;
        }
    }

    llpivotRecursive(nextNode, smaller, larger, pivot, lastSmaller, lastLarger); // Recursive call
}

// Wrapper function for llpivot to hide the details of lastSmaller and lastLarger from the caller
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    smaller = nullptr;
    larger = nullptr;
    Node* lastSmaller = nullptr;
    Node* lastLarger = nullptr;
    llpivotRecursive(head, smaller, larger, pivot, lastSmaller, lastLarger);
    head = nullptr; // Since the original list is partitioned, the head is now null.
}
