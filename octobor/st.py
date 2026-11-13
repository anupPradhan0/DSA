"""Middle of the Linked List

Given the head of a singly linked list, return its middle node.

If the list has an even number of nodes, return the second middle node.

Examples:
	0 -> 1 -> 2 -> 3 -> 4  returns 2
	0 -> 1 -> 2 -> 3 -> 4 -> 5  returns 3

Plan:
	1. Create a slow pointer and a fast pointer at the head.
	2. Move slow one node at a time.
	3. Move fast two nodes at a time.
	4. When fast reaches the end, slow is at the middle.

Target complexity: O(n) time and O(1) extra space.
"""

from typing import Optional


class ListNode:
	def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
		self.val = val
		self.next = next


class Solution:
	def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
		slow = head
		fast = head
		while fast and fast.next:
			slow = slow.next
			fast = fast.next.next
		return slow
	