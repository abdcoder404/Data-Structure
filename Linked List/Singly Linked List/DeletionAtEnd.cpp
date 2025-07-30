#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Deletion at End + Insert + Traverse
// ----------------------------------------

struct Node {
int data;
Node* next;
};

Node* head = nullptr;

void insert(int value) {
// Step 1: Create new node
Node* newNode = new Node;

// Step 2: Assign data  
newNode->data = value;  

// Step 3: Point new node to current head  
newNode->next = head;  

// Step 4: Update head to new node  
head = newNode;

}

void deleteAtEnd() {
// Case 1: List is empty
if (head == nullptr) {
cout << "List is empty. Nothing to delete." << endl;
return;
}

// Case 2: Only one node exists  
if (head->next == nullptr) {  
    delete head;  
    head = nullptr;  
    cout << "Last node deleted. List is now empty." << endl;  
    return;  
}  

// Case 3: More than one node  
Node* temp = head;  

// Traverse to the second last node  
while (temp->next->next != nullptr) {  
    temp = temp->next;  
}  

// Delete the last node and set next of second last to null  
delete temp->next;  
temp->next = nullptr;  

cout << "Last node deleted successfully." << endl;

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

insert(10);     
insert(20);     
insert(30);     

traverse();    
deleteAtEnd();      

deleteAtEnd();      
traverse();  

deleteAtEnd();      

return 0;

}
