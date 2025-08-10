#include <iostream>  
using namespace std;  
  
/* ==========================================  
     Singly Circular Linked List  
     - DELETE at Specific Position  
   ==========================================  
  
   - DELETE at Specific Position (1-based index):  
     - If list is empty: do nothing.  
     - If position = 1:  
         -> Write code of delete at beginning.   
     - Else:  
         -> Traverse to (pos - 1)th node.  
         -> If position is invalid: do nothing.  
         -> Adjust pointers to skip the node.  
         -> Delete the target node.  
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
  
void deleteAtPosition(int position) {  
    if (head == nullptr || position < 1) {  
        cout << "Invalid operation." << endl;  
        return;  
    }  
  
    // - Case 1: Delete at beginning  
    if (position == 1) {  
        if (head->next == head) {  
            delete head;  
            head = nullptr;  
        } else {  
            Node* last = head;  
            while (last->next != head) {  
                last = last->next;  
            }  
  
            Node* temp = head;  
            head = head->next;  
            last->next = head;  
            delete temp;  
        }  
        return;  
    }  
  
    // - Case 2: Delete at position > 1  
    Node* curr = head;  
    Node* prev = nullptr;  
  
    int count = 1;  
    while (count < position && curr->next != head) {  
        prev = curr;  
        curr = curr->next;  
        count++;  
    }  
  
    if (count != position) {  
        cout << "Position out of range." << endl;  
        return;  
    }  
  
    prev->next = curr->next;  
    delete curr;  
}  
  
int main() {  
    insertAtBeginning(50);  
    insertAtBeginning(40);  
    insertAtBeginning(30);  
    insertAtBeginning(20);  
    insertAtBeginning(10);  
  
    traverse();  
  
    deleteAtPosition(3);  
    cout << "After deleting position 3:" << endl;  
    traverse();  
  
    deleteAtPosition(1);  
    cout << "After deleting position 1:" << endl;  
    traverse();  
  
    deleteAtPosition(10);  
    return 0;  
}
