#include <iostream>
using namespace std;

/* =====================================================
    Singly Circular Linked List:            
    INSERT at Specific Position               
   =====================================================
*/

/*
  - INSERTION at Specific Position:

    - Create a new node with given data.
    - If position is 1:
      - Same as insert at beginning.
      - Traverse to last node and update pointers.
    - Else:
      - Traverse to (position - 1) node using a loop.
      - Insert the new node by updating pointers.
*/

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtPosition(int value, int pos) {
    Node* newNode = new Node;
    newNode->data = value;

    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (head == nullptr) {
        if (pos == 1) {
            newNode->next = newNode;
            head = newNode;
        } else {
            cout << "Position out of bounds for empty list." << endl;
            delete newNode;
        }
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 1; i < pos - 1; ++i) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position out of bounds." << endl;
                delete newNode;
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
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

int main() {
    insertAtPosition(10, 1);  
    insertAtPosition(20, 2);  
    insertAtPosition(15, 2);  
    insertAtPosition(5, 1);   

    traverse();

    return 0;
}
