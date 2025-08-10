#include<iostream>
using namespace std;
// ------------------------------------------------------
// Topic:
// Doubly Linked List - Deletion at End
// ------------------------------------------------------

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void traverse() {
    if (head == nullptr) {
        cout << "No element present." << endl;
        return;
    }

    Node* temp = head;
    cout << "Values in list:" << endl;
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

    traverse();

    return 0;
}
