
#include <iostream>

using namespace std;

/**
 * Definition for a singly-linked list node.
 *
 * Each node contains:
 * - val: The integer value stored in the node.
 * - next: A pointer to the next node in the list.
 */
struct ListNode {
    int val;
    ListNode* next;

    // Constructor: Initialize a node with value 0.
    ListNode() : val(0), next(nullptr) {}

    // Constructor: Initialize a node with a given value.
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor: Initialize a node with a value and next pointer.
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Finds and returns the middle node of a linked list.
     *
     * @param head Pointer to the first node of the linked list.
     * @return Pointer to the middle node.
     *
     * If the list has an even number of nodes, returns
     * the second of the two middle nodes.
     */
    ListNode* middleNode(ListNode* head) {
        // Initialize both pointers at the first node.
        ListNode* slow = head;
        ListNode* fast = head;

        // Continue while fast can safely move two nodes.
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow forward by one node.
            slow = slow->next;

            // Move fast forward by two nodes.
            fast = fast->next->next;
        }

        // Slow now points to the middle node.
        return slow;
    }
};

/**
 * Prints all node values in a linked list.
 *
 * @param head Pointer to the first node.
 */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << " -> nullptr" << endl;
}

int main() {
    // Create a linked list containing 10 nodes (1 through 10).
    ListNode* head = new ListNode(1);
    ListNode* current = head;

    for (int i = 2; i <= 10; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }

    // Display the original linked list.
    cout << "Original linked list:" << endl;
    printList(head);

    // Find the middle node.
    Solution solution;
    ListNode* middle = solution.middleNode(head);

    // Display the middle node and the remaining list.
    cout << "\nMiddle node value: " << middle->val << endl;
    cout << "List starting from the middle node:" << endl;
    printList(middle);

    // Free the allocated memory.
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
