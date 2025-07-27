#### What is a Singly Linked List?

A singly linked list is a linear data structure used to store a sequence of elements.
Each element in the list is called a node.

#### Structure of a Node

Each node in a singly linked list has three main components:

- Data: the actual value stored in the node


- Next: a pointer (or reference) to the next node in the list


- Head: a special pointer that always points to the first node in the list


The last node’s Next points to None (or nullptr), which indicates the end of the list.

#### Key Features

- ##### One-way traversal:

You can only move forward through the list, from one node to the next.

- ##### Dynamic size: 

You can easily add or remove nodes without needing to resize memory (unlike arrays).

- ##### Sequential access only: 

To find a specific element, you must start from the head and move through each node one by one.


