#include <iostream>
using namespace std;

// ----------------------------------------
// Topic:
// Singly Linked List – Bubble Sort (Ascending)
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

void bubbleSort() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to sort." << endl;
        return;
    }

    bool swapped;
    Node* temp;
    Node* check = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != check) {
            if (temp->data > temp->next->data) { // Change '>' to '<' for descending order
                int swap = temp->data;
                temp->data = temp->next->data;
                temp->next->data = swap;
                swapped = true;
            }
            temp = temp->next;
        }

        check = temp;
    } while (swapped);
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

    cout << "Before sorting:" << endl;
    printList();

    bubbleSort();

    cout << "After sorting:" << endl;
    printList();

    return 0;
}
