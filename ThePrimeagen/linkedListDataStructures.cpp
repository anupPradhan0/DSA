// Linked List Data Structures
//
// A linked list is a chain of nodes.
// Each node stores:
// - a value
// - a pointer to the next node
//
// In this example, we keep a pointer to the first node called `head`.
// That makes adding or removing the first element very fast.
//
// Big idea:
// - pushFront: O(1)
// - remove from front: O(1)
// - pushBack/search/remove from middle: O(n)

#include <iostream>

struct Node {
	int value;
	Node* next;

	explicit Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
public:
	// Destructor: clean up all allocated nodes so we do not leak memory.
	~LinkedList() {
		clear();
	}

	// Add a new value at the front of the list.
	void pushFront(int value) {
		Node* node = new Node(value);
		// The new node points to the old first node.
		node->next = head;
		// Move head to the new node.
		head = node;
	}

	// Add a new value at the end of the list.
	void pushBack(int value) {
		Node* node = new Node(value);

		if (head == nullptr) {
			// If the list is empty, the new node becomes the first node.
			head = node;
			return;
		}

		// Walk until we find the last node.
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}

		// Attach the new node after the last node.
		current->next = node;
	}

	// Remove the first node that contains the given value.
	bool remove(int value) {
		if (head == nullptr) {
			// Nothing to remove if the list is empty.
			return false;
		}

		if (head->value == value) {
			// Special case: removing the first node.
			Node* deleted = head;
			head = head->next;
			delete deleted;
			return true;
		}

		// Find the node just before the one we want to delete.
		Node* current = head;
		while (current->next != nullptr && current->next->value != value) {
			current = current->next;
		}

		if (current->next == nullptr) {
			// We reached the end and did not find the value.
			return false;
		}

		// Skip over the node we want to delete.
		Node* deleted = current->next;
		current->next = current->next->next;
		delete deleted;
		return true;
	}

	// Print the list from left to right.
	void print() const {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->value;
			if (current->next != nullptr) {
				std::cout << " -> ";
			}
			current = current->next;
		}
		std::cout << '\n';
	}

	// Delete every node in the list.
	void clear() {
		while (head != nullptr) {
			Node* deleted = head;
			head = head->next;
			delete deleted;
		}
	}

private:
	Node* head = nullptr;
};

int main() {
	LinkedList list;

	// Build the list: 1 -> 2 -> 3 -> 4
	list.pushFront(3);
	list.pushFront(2);
	list.pushFront(1);
	list.pushBack(4);

	// Show the list before removing anything.
	std::cout << "Initial list: ";
	list.print();

	// Remove the node with value 2.
	list.remove(2);

	// Show the updated list.
	std::cout << "After removing 2: ";
	list.print();

	return 0;
}

