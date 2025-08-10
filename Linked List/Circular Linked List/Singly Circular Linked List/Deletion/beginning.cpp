#include <iostream>
using namespace std;

/* ==========================================
     Singly Circular Linked List
     - DELETE at Beginning   
   ==========================================

   - DELETE at Beginning:
     - If list is empty: nothing to delete.
     - If only one node: delete it, set head = nullptr.
     - Else:
       - Traverse to the last node.
       - Move head to next node.
       - Point last node's next to new head.
       - Delete old head.
*/

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void traverse() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
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
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }

    // - Case 2: More than one node
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

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
