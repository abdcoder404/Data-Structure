#include <iostream>  
using namespace std;  
  
/* =====================================================  
    Singly Circular Linked List:            
    INSERT at End                
   =====================================================  
*/  
  
/*  
  - INSERTION at End:  
    - Create a new node with given data.  
    - If the list is empty:  
      - Set newNode->next = newNode  
      - Set head = newNode  
    - If list is not empty:  
      - Traverse to the last node (temp->next == head)  
      - Set newNode->next = head  
      - Set lastNode->next = newNode  
  
  - TRAVERSAL:  
    - Start at head.  
    - Use a do-while loop to visit each node.  
    - Continue until you loop back to the head.  
  
*/  
  
struct Node {  
    int data;  
    Node* next;  
};  
  
Node* head = nullptr;  
  
void insertAtEnd(int value) {  
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
        temp->next = newNode;  
        newNode->next = head;  
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
    insertAtEnd(10);  
    insertAtEnd(20);  
    insertAtEnd(30);  
  
    traverse();  
  
    return 0;  
}
