#include <iostream>
using namespace std;

// Definition for a singly-linked list node
struct ListNode
{
    int val;
    ListNode* next;

    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor with a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with a value and next node
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    /*
     * Reverse a singly linked list.
     *
     * We use three pointers:
     * prev  -> points to the previous node
     * curr  -> points to the current node
     * next  -> temporarily saves the next node
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    ListNode* reverseList(ListNode* head)
    {
        // Initially, there is no previous node.
        ListNode* prev = nullptr;

        // Start at the head of the list.
        ListNode* curr = head;

        while (curr != nullptr)
        {
            // Save the next node before changing curr->next.
            ListNode* next = curr->next;

            // Reverse the current node's pointer.
            curr->next = prev;

            // Move prev to the current node.
            prev = curr;

            // Move curr to the next node.
            curr = next;
        }

        // prev is now the new head of the reversed list.
        return prev;
    }
};

// Print the linked list
void printList(ListNode* head)
{
    ListNode* curr = head;
    // Use while loop to iterate all of the Nodes
    while (curr != nullptr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }

    cout << "nullptr" << endl;
}

int main()
{
    // Create the nodes
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Set node1 as the head
    ListNode* head = node1;

    // Display the original list
    cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Display the reversed list
    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}

