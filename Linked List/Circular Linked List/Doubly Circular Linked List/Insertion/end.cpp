#include <iostream>
using namespace std;

/* ==========================================
     Doubly Circular Linked List
     - INSERT at End
     - TRAVERSE
   ==========================================

   - INSERT at End:
     - If list is empty:
       - newNode's next and prev point to itself.
       - head = newNode.
     - Else:
       - Find last node (head->prev).
       - Link newNode after last node.
       - Update head->prev to newNode.
       - Maintain circular structure.

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
    } else {
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
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

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    traverse();

    return 0;
}
