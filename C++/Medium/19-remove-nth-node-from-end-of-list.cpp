
#include <iostream>

using namespace std;

/**
 * Definition for a singly linked list node.
 *
 * Each node stores an integer value and a pointer
 * to the next node in the list.
 */
struct ListNode {
    int val;
    ListNode* next;

    // Constructor: Creates a node with a default value of 0.
    ListNode() : val(0), next(nullptr) {}

    // Constructor: Creates a node with a given value.
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor: Creates a node with a value and a next pointer.
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Removes the nth node from the end of the linked list.
     *
     * @param head Pointer to the first node of the linked list.
     * @param n    Position of the node to remove, counted from the end.
     * @return     Pointer to the head of the updated linked list.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node before the head.
        // This simplifies removing the first node when necessary.
        ListNode* dummy = new ListNode(0, head);

        // Initialize both pointers at the dummy node.
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n nodes ahead to establish a gap of n nodes.
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers together until fast reaches the last node.
        // slow will then point to the node before the target node.
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Store the address of the node that must be removed.
        ListNode* nodeDelete = slow->next;

        // Skip the target node by connecting slow to the next node
        // after the target.
        slow->next = slow->next->next;

        // Save the updated head before deleting the dummy node.
        ListNode* result = dummy->next;

        // Free the memory used by the removed node and dummy node.
        delete nodeDelete;
        delete dummy;

        // Return the head of the updated linked list.
        return result;
    }
};

/**
 * Prints the linked list without modifying the original head pointer.
 *
 * @param head Pointer to the first node of the linked list.
 */
void printList(ListNode* head) {
    // Traverse the list until the end is reached.
    while (head != nullptr) {
        cout << head->val;

        // Print an arrow if another node follows.
        if (head->next != nullptr) {
            cout << " -> ";
        }

        // Advance to the next node.
        head = head->next;
    }

    cout << " -> nullptr\n";
}

/**
 * Main function for testing the solution locally.
 */
int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Remove the 2nd node from the end (node with value 4).
    int n = 2;

    cout << "Before: ";
    printList(head);

    // Create a Solution object and remove the target node.
    Solution solution;
    head = solution.removeNthFromEnd(head, n);

    cout << "After:  ";
    printList(head);

    // Free the memory of all remaining nodes.
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
