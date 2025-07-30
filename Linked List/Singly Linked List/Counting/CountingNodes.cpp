#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Count Total Nodes
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

void countNodes() {
int count = 0;
Node* temp = head;

while (temp != nullptr) {  
    count++;  
    temp = temp->next;  
}  

cout << "Number of nodes in the list: " << count << endl;

}

void printList() {
Node* temp = head;
cout << "Linked List: ";

if (temp == nullptr) {  
    cout << "(Empty List)" << endl;  
    return;  
}  

while (temp != nullptr) {  
    cout << temp->data << " -> ";  
    temp = temp->next;  
}  
cout << "NULL" << endl;

}

int main() {
insert(5);
insert(103);
insert(500);
insert(1033);

printList();       
countNodes();      

return 0;

}
