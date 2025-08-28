#include "UnsortedLinkedListDict.hpp"
void UnsortedLinkedListDict::insert(int key) {
	Node* x = new Node(key);

	x -> next = head;
	head = x;
}
bool UnsortedLinkedListDict::lookup(int key) const {
	Node* curr = head;

	while (curr && key != curr -> data) {
		curr = curr->next;
	}

	return curr != nullptr;
}
void UnsortedLinkedListDict::remove(int key) {
	if (!head) {
		return;
	}

	if (head -> data == key) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* curr = head;

	while (curr -> next && key != curr -> next -> data) {
		curr = curr -> next;
	}

	if (curr->next && key == curr->next->data) {
		Node* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
}