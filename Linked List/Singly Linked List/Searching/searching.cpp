#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Searching
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

void search(int value) {
    Node* temp = head;
    int position = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Element " << value << " found at position " << position << "." << endl;
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Element " << value << " not found in the list." << endl;
    }
}

void print() {
    Node* temp = head;
    cout << "Linked List contents: ";
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

    print();
    search(500);
    search(55);

    return 0;
}
