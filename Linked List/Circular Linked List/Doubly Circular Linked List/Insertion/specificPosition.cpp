#include <iostream>
using namespace std;

/* ==========================================
     Doubly Circular Linked List
     - INSERT at Specific Position
   ==========================================

   - INSERT at Specific Position:
     - Position 1 → Same as insertion at beginning.
     - If list is empty and pos > 1 → Invalid.
     - Else:
       - Traverse to (pos - 1)th node.
       - Link newNode between prevNode and currentNode.
       - Maintain circular links (prev and next pointers) both ways.
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtSpecificPosition(int value, int pos) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        if (pos != 1) {
            cout << "Invalid position. List is empty." << endl;
            delete newNode;
            return;
        }
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    if (pos == 1) {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        cout << "Invalid position." << endl;
        delete newNode;
        return;
    }

    Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;
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
    insertAtSpecificPosition(10, 1);
    insertAtSpecificPosition(20, 2);
    insertAtSpecificPosition(30, 3);
    insertAtSpecificPosition(15, 2);

    traverse();

    return 0;
}
