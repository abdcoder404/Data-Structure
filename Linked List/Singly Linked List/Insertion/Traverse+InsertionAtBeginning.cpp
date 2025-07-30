#include <iostream>  
using namespace std;  
  
// ----------------------------------------  
//  Traverse + Insertion At The Beginning In Singly Linked List:  
// ----------------------------------------  
  
// --------------------  
// Insertion Steps:  
// --------------------  
// 1. Create a new node using dynamic memory allocation.  
// 2. Assign the data value to this node.  
// 3. Set the new node's 'next' pointer to the current Head (i.e., first node).  
// 4. Update Head to point to the new node (new node becomes the first node).  
//  
// --------------------  
// Traversal Steps:  
// --------------------  
// 1. Start from the Head node.  
// 2. While the current node is not NULL:  
//     - Print the node's data.  
//     - Move to the next node using the 'next' pointer.  
// --------------------  
  
struct Node {  
    int data;        
    Node* next;      
};  
  
Node* Head = nullptr;  
  
void insertAtBeginning(int value) {  
  
    Node* newNode = new Node;  

    newNode->data = value;  
    newNode->next = Head;  
  
    Head = newNode;  
}  
  
void traverse() {  
    cout << "Values in the linked list are: " << endl;  
 
    Node* temp = Head;  
  
    while (temp != nullptr) {  
      
        cout << temp->data << endl; 
        temp = temp->next;  
      
    }  
}  
  
int main() {  
     
    insertAtBeginning(4);  
    insertAtBeginning(7);
      
    traverse();  
  
    return 0;  
}
