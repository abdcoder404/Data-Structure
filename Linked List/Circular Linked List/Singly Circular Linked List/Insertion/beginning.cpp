#include <iostream>
using namespace std;

/* ==========================================================
    Singly Circular Linked List in C++           
    ● INSERT at Beginning  
    ● TRAVERSE the List            
   ==========================================================

   ● What is a Singly Circular Linked List?

     - The last node doesn't point to NULL.
     - Instead, it points back to the first node.
     - This creates a continuous circle, making traversal possible from any node.

   ● INSERTION at Beginning:

     1. Create a new node with given data.
     2. If the list is empty:
        → Point newNode->next to itself (circular)
        → Set head = newNode
     3. If list is not empty:
        → Traverse to the last node (whose next points to head)
        → Set newNode->next = head
        → Set lastNode->next = newNode
        → Update head = newNode
     
     → This inserts the new node before the current head
       and correctly updates the circular link.

   ● TRAVERSAL:

     - Start at the head.
     - Print the current node.
     - Move to next node and repeat.
     - Stop when you reach back to the head.

   ● Why use do while loop?

     - Because in a circular list, the loop should run 
       at least once even if only one node exists.

     - If we used while(temp != head) from the start, 
       the condition would fail immediately when 
       there's only one node, and it won't print anything!

     - do while ensures the first node is always printed.
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
        newNode->next = newNode;  // Circular link to self
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

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    traverse();

    return 0;
}
