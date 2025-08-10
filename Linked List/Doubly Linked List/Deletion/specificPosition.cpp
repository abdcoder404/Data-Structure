#include<iostream>
using namespace std;
// ------------------------------------------------------
// Topic:
// Doubly Linked List - Deletion at Specific Position
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

void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

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
    insert(40);

    traverse();

    deleteAtPosition(3);

    traverse();

    return 0;
}
