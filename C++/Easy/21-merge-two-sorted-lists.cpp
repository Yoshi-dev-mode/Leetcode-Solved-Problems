
/*
 * LeetCode 21: Merge Two Sorted Lists
 *
 * Description:
 * Merge two sorted linked lists into one sorted linked list.
 * The merged list is created by reusing the nodes from the
 * original lists instead of creating new nodes for every value.
 *
 * Approach:
 * 1. Create a dummy node to simplify the merging process.
 * 2. Use a tail pointer to track the end of the merged list.
 * 3. Compare the current values of both lists.
 * 4. Attach the smaller node and advance its list pointer.
 * 5. Attach any remaining nodes after one list becomes empty.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1) auxiliary space
 */

#include <iostream>
using namespace std;

// Definition of a singly linked list node.
struct ListNode {
    int val;
    ListNode* next;

    // Initialize a node with a default value of 0.
    ListNode() : val(0), next(nullptr) {}

    // Initialize a node with a given value.
    ListNode(int x) : val(x), next(nullptr) {}

    // Initialize a node with a value and next pointer.
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Merge two sorted linked lists and return the merged list.
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node acts as a temporary starting point.
        ListNode dummy(0);

        // Tail points to the last node in the merged list.
        ListNode* tail = &dummy;

        // Continue until one of the lists becomes empty.
        while (list1 != nullptr && list2 != nullptr) {

            // If list1's value is smaller or equal, select it.
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;  // Advance list1.
            }
            else {
                // Otherwise, select the node from list2.
                tail->next = list2;
                list2 = list2->next;  // Advance list2.
            }

            // Move tail to the node that was just attached.
            tail = tail->next;
        }

        // Attach the remaining nodes from the non-empty list.
        if (list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        // Skip the dummy node and return the actual merged list.
        return dummy.next;
    }
};

// Print all values in a linked list.
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

// Create a linked list from an array of values.
ListNode* createList(int arr[], int size) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int i = 0; i < size; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }

    return dummy.next;
}

// Release the dynamically allocated nodes.
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Two sorted linked lists for testing.
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge the two lists.
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    // Free the merged list's nodes once.
    // The original list pointers now refer to nodes
    // that belong to the merged list.
    deleteList(mergedList);

    return 0;
}
