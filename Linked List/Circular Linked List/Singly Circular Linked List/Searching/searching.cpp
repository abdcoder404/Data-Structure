#include <iostream>
using namespace std;

/* ==========================================
     Singly Circular Linked List
     - SEARCH for a value
   ==========================================

   - SEARCH:
     - Traverse using do-while
     - Compare each node’s data
     - If found: return position (1-based)
     - If not: return -1
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

int search(int key) {
    if (head == nullptr) { return -1; }

    Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) { return pos; }
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    int val = 20;
    int result = search(val);
    if (result != -1)
        cout << val << " found at position: " << result << endl;
    else
        cout << val << " not found." << endl;

    return 0;
}
