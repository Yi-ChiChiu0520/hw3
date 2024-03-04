#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void append(Node*& list, Node*& node) {
    if (list == nullptr) {
        // If the list is empty, the node becomes the new head.
        list = node;
        node->next = nullptr; // Ensure the appended node's next is nullptr.
    } else {
        // If the list is not empty, iterate to the end and add the node.
        Node* current = list;
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = node; // the current last node's next will be the target node
        node->next = nullptr; 
    }
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    // Base case is when head is nullptr
    if (head == nullptr) {
        return;
    }

    // Save the next node
    Node* nextNode = head->next;

    // Detach the current node from the list.
    head->next = nullptr;

    // if current node's value is smaller then pivot , add to smaller list
    if (head->val <= pivot) {
        append(smaller, head);
    } else {
        // if current node's value is larger then pivot , add to larger list
        append(larger, head);
    }

    llpivot(nextNode, smaller, larger, pivot);
}
