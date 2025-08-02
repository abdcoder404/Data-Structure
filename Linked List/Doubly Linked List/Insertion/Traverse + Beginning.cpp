#include <iostream>
using namespace std;

// ----------------------------------------
// Topic: Doubly Linked List - Insert at Beginning and Traverse
// ----------------------------------------

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

void traverse() {
    if (head == nullptr) {
        cout << "No element present in the list." << endl;
        return;
    }

    Node* temp = head;
    cout << "Values in list: " << endl;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    insertAtBeginning(5);
    insertAtBeginning(20);
    insertAtBeginning(100);

    traverse();

    return 0;
}
