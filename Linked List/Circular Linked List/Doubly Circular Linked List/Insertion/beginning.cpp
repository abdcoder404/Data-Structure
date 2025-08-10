#include <iostream>
using namespace std;

/* ==========================================
     Doubly Circular Linked List
     - INSERT at Beginning
     - TRAVERSE
   ==========================================

   - INSERT at Beginning:
     - If list is empty:
       - newNode's next and prev point to itself.
       - head = newNode.
     - Else:
       - Link newNode before head.
       - Update head's prev to newNode.
       - Update last node's next to newNode.
       - Make newNode the new head.

   - TRAVERSE:
     - Start from head, move forward until you reach head again.
     - Print each node's data.
     - Uses do-while loop to ensure the first node is always printed.
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
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

        head = newNode;
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
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    traverse();

    return 0;
}
