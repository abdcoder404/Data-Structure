#include <iostream>
using namespace std;
// ------------------------------------------------------
// Topic:
// Deletion At Beginning in Doubly Linked List
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

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

void traverse() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "List elements:" << endl;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insert(30);
    insert(20);
    insert(10);

    traverse();

    deleteAtBeginning();
    traverse();

    return 0;
}
