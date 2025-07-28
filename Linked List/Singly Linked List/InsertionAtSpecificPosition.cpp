#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List - Insertion at Specific Position + Traverse
// ----------------------------------------

struct Node {
int data;
Node* next;
};

Node* head = nullptr;

void insertAtSpecificPosition(int position, int value) {
if (position < 1) {
cout << "Invalid position! Position must be >= 1\n";
return;
}

// Create the new node
Node* newNode = new Node;
newNode->data = value;
newNode->next = nullptr;

// If inserting at the beginning
if (position == 1) {
newNode->next = head;
head = newNode;
return;
}

// Traverse to the (position - 1)th node
// Because we want to insert after that

Node* temp = head;
for (int i = 1; i < position - 1; i++) {
temp = temp->next;
if (temp == nullptr) {
cout << "Position out of range\n";
return;
}
}

// Insert the new node
newNode->next = temp->next;
temp->next = newNode;

}

void traverse() {
cout << "Values in the linked list are: " << endl;
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << endl;
temp = temp->next;
}
}

int main() {
insertAtSpecificPosition(1, 10);
insertAtSpecificPosition(2, 20);
insertAtSpecificPosition(2, 15);

traverse();

return 0;

}
