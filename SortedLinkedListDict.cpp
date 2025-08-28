#include "SortedLinkedListDict.hpp"
void SortedLinkedListDict::insert(int key) {
	Node* x = new Node(key);

	if (!head || key < head -> data) {
		x -> next = head;
		head = x;
		return;
	}

	Node* curr = head;

	while (curr -> next && key >= curr -> next -> data) {
		curr = curr -> next;
	}

	x -> next = curr -> next;
	curr -> next = x;
}
bool SortedLinkedListDict::lookup(int key) const {
	Node* curr = head;

	while(curr && key > curr -> data && curr -> next) {
		curr = curr -> next;
	}

	return curr && curr -> data == key;
}
void SortedLinkedListDict::remove(int key) {
	if (!head) {
		return;
	}
	if (head -> data == key) {
		Node* temp = head;
		head = head -> next;
		delete temp;
		return;
	}

	Node* curr = head;

	while (curr -> next && key > curr -> next -> data) {
		curr = curr -> next;
	}

	if (curr -> next && curr -> next -> data == key) {
		Node* temp = curr -> next;
		curr -> next = temp -> next;
		delete temp;
	}
}