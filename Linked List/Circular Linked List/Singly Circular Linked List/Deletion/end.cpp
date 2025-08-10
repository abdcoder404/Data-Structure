#include <iostream>
using namespace std;

/* ==========================================
     Singly Circular Linked List
     - DELETE at End   
   ==========================================

   - DELETE at End:
     - If list is empty: nothing to delete.
     - If only one node: delete it, set head = nullptr.
     - Else:
       - Traverse to second last node.
       - Set its next to head.
       - Delete last node.
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

void deleteAtEnd() {
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
    Node* current = head;
    Node* prev = nullptr;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    delete current;
}

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    traverse();

    deleteAtEnd();
    cout << "After deletion at end:" << endl;
    traverse();

    deleteAtEnd();
    deleteAtEnd();
    cout << "After deleting all elements:" << endl;
    traverse();

    deleteAtEnd();  

    return 0;
}
