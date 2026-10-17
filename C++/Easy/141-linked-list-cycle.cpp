
#include <iostream>

using namespace std;

/**
 * Definition for a singly linked list node.
 * Each node stores an integer value and a pointer
 * to the next node in the linked list.
 */
struct ListNode {
    int val;
    ListNode* next;

    // Constructor initializes the node's value and next pointer.
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * Determines whether a linked list contains a cycle.
     *
     * Uses Floyd's Cycle Detection Algorithm (slow and fast pointers).
     *
     * @param head Pointer to the first node of the linked list.
     * @return true if a cycle exists, otherwise false.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    bool hasCycle(ListNode* head) {

        // Initialize both pointers at the head of the list.
        ListNode* slow = head;
        ListNode* fast = head;

        // Continue while fast can safely move two steps.
        // If fast reaches nullptr, the list has no cycle.
        while (fast != nullptr && fast->next != nullptr) {

            // Move slow one node forward.
            slow = slow->next;

            // Move fast two nodes forward.
            fast = fast->next->next;

            // If both pointers meet, a cycle exists.
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached the end of the list.
        // Therefore, no cycle exists.
        return false;
    }
};

/**
 * Main function to test the cycle detection algorithm.
 */
int main() {

    // Create four nodes.
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Connect the nodes to form a linked list.
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a cycle: the last node points back to node2.
    node4->next = node2;

    // Create a Solution object.
    Solution solution;

    // Check whether the linked list contains a cycle.
    bool result = solution.hasCycle(node1);

    // Print the result.
    cout << boolalpha;
    cout << "Contains cycle: " << result << endl;

    // Break the cycle before deleting the nodes.
    node4->next = nullptr;

    // Free the dynamically allocated memory.
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
