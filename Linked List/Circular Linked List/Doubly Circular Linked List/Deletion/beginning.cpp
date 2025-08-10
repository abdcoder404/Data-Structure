#include <iostream>
using namespace std;

/* ==========================================
     Doubly Circular Linked List
     - DELETE at Beginning
   ==========================================

   - DELETE at Beginning:
     - If list is empty → Nothing to delete.
     - If only one node → Delete it, set head = nullptr.
     - Else:
       - Move head to the next node.
       - Update last node's next to new head.
       - Update new head's prev to last node.
       - Delete old head.
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
}

void traverse() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Doubly Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // - Case 1: Only one node
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // - Case 2: More than one node
    Node* last = head->prev;
    Node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    delete temp;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    traverse();

    deleteAtBeginning();
    cout << "After deletion at beginning:" << endl;
    traverse();

    deleteAtBeginning();
    deleteAtBeginning();
    cout << "After deleting all elements:" << endl;
    traverse();

    deleteAtBeginning();

    return 0;
}
