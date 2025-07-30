#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Deletion at Beginning + Insert + Traverse
// ----------------------------------------

struct Node {
int data;
Node* next;
};

Node* head = nullptr;

void insert(int value) {
// Step 1: Create a new node
Node* newNode = new Node;

// Step 2: Assign data to the new node  
newNode->data = value;  

// Step 3: Point new node's next to current head  
newNode->next = head;  

// Step 4: Move head to point to new node  
head = newNode;

}

void deleteAtBeginning() {
// Step 1: Check if list is empty
if (head == nullptr) {
cout << "List is empty. Nothing to delete." << endl;
return;
}

// Step 2: Store current head in a temp pointer  
Node* temp = head;  

// Step 3: Move head to the next node  
head = head->next;  

// Step 4: Free memory of old head  
delete temp;  

cout << "First node deleted successfully." << endl;

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

deleteAtBeginning();    
traverse();                  

deleteAtBeginning();    

return 0;

}
