#include <iostream>  
using namespace std;  

// ----------------------------------------  
// Topic:  
// Singly Linked List - Insertion at the End + Traversal  
// ----------------------------------------  

// Node structure
struct Node {  
    int data;      
    Node* next;    
};  
    
Node* head = nullptr;  
    
void insertAtEnd(int value) {  
    // Step 1: Create a new node
    Node* newNode = new Node;  
    newNode->data = value;  
    newNode->next = nullptr;  
  
    // Step 2: If the list is empty, new node becomes head  
    if (head == nullptr) {  
        head = newNode;  
        return;  
    }  
  
    // Step 3: Traverse to the last node  
    Node* temp = head;  
    while (temp->next != nullptr) {  
        temp = temp->next;  
    }  
  
    // Step 4: Link the last node to the new node  
    temp->next = newNode;  
}  
    
void traverse() {  
    cout << "Values in the linked list are:" << endl;  
  
    Node* temp = head;  
    while (temp != nullptr) {  
        cout << temp->data << endl;  
        temp = temp->next;  
    }  
}  
  
int main() {  
    
    insertAtEnd(5);      
    insertAtEnd(10);     
    insertAtEnd(15);     
    
    traverse();  
  
    return 0;  
}
