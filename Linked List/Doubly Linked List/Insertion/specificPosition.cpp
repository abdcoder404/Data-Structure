#include<iostream>
using namespace std;
// ------------------------------------------------------
// Topic:
// Doubly Linked List - Insertion at Specific Position
// ------------------------------------------------------

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
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
    insertAtPosition(5, 1);
    insertAtPosition(103, 2);
    insertAtPosition(500, 3);
    insertAtPosition(1033, 2);
    traverse();

    return 0;
}
