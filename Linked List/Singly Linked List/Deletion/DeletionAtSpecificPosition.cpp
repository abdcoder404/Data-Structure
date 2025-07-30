#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Deletion at Specific Position + Insert + Traverse
// ----------------------------------------

struct Node {
int data;
Node* next;
};

Node* head = nullptr;

void insert(int value) {
Node* newNode = new Node;
newNode->data = value;
newNode->next = head;
head = newNode;
}

void deleteAtPosition(int position) {
if (head == nullptr) {
cout << "List is empty. Nothing to delete." << endl;
return;
}

if (position < 1) {  
    cout << "Invalid position! Position must be >= 1" << endl;  
    return;  
}  

// Case: Delete the first node  
if (position == 1) {  
    Node* temp = head;  
    head = head->next;  
    delete temp;  
    cout << "Node at position 1 deleted successfully." << endl;  
    return;  
}  

// Traverse to (position - 1)th node  
Node* temp = head;  
for (int i = 1; i < position - 1; i++) {  
    if (temp == nullptr || temp->next == nullptr) {  
        cout << "Position out of range." << endl;  
        return;  
    }  
    temp = temp->next;  
}  

Node* nodeToDelete = temp->next;  
temp->next = nodeToDelete->next;  
delete nodeToDelete;  

cout << "Node at position " << position << " deleted successfully." << endl;

}

void traverse() {
cout << "Values in the linked list are:" << endl;
Node* temp = head;

if (temp == nullptr) {  
    cout << "(Empty List)" << endl;  
    return;  
}  

while (temp != nullptr) {  
    cout << temp->data << endl;  
    temp = temp->next;  
}

}

int main() {
insert(40);
insert(30);
insert(20);
insert(10);

traverse();  

deleteAtPosition(2);    
traverse();  

deleteAtPosition(1);    
traverse();  

deleteAtPosition(5);    
traverse();  

return 0;

}
