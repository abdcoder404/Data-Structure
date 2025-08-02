#include<iostream>
using namespace std;
// ------------------------------------------------------
// Topic:
// Doubly Linked List - Insertion at End
// ------------------------------------------------------

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    if(head == nullptr) {
        Node* newNode = new Node;
        newNode -> data = value;
        newNode -> next = head;
        newNode -> prev = nullptr;   
        head = newNode;
        return;     
    }
    
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> next = nullptr;
    
    Node* temp = head;
    while(temp -> next != nullptr) {
        temp = temp -> next;
    }
    
    newNode -> prev = temp;
    temp -> next = newNode;
}

void traverse() {
    if(head == nullptr) {
        cout << "No element present." << endl;
        return;
    }
    Node* temp = head;
    cout << "Values in list: " << endl;
    while(temp != nullptr) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

int main() {
    insertAtEnd(5);
    insertAtEnd(103);
    insertAtEnd(500);
    insertAtEnd(1033);
    traverse();

    return 0;
}
