# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def reverseList(self, head):
        """
        Reverse a singly linked list and return the new head.

        The algorithm uses two pointers:
        - prev: keeps track of the previous node
        - curr: keeps track of the current node

        For each node, its `next` pointer is changed to point
        to the previous node. This reverses the direction of
        the linked list one node at a time.

        Args:
            head (Optional[ListNode]): The head of the linked list.

        Returns:
            Optional[ListNode]: The new head of the reversed list.

        Time Complexity:
            O(n) - Each node is visited once.

        Space Complexity:
            O(1) - No extra data structure is used.
        """

        # Previous node starts as None because the
        # new tail of the reversed list points to None.
        prev = None

        # Start at the first node of the linked list.
        curr = head

        # Continue until we reach the end of the list.
        while curr:

            # Save the next node before changing curr.next.
            # Otherwise, we would lose the rest of the list.
            nextNode = curr.next

            # Reverse the current node's pointer.
            curr.next = prev

            # Move prev forward to the current node.
            prev = curr

            # Move curr forward to the saved next node.
            curr = nextNode

        # prev is now the new head of the reversed list.
        return prev