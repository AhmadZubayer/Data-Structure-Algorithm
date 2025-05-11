#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
     // a pointer to another Node object
     // Stores the memory address of the next node
};
// // Node* something always means that something is a pointer to a Node object

// create and return a single new node.
Node *createNode(int data) {
    // returning a pointer (i.e., the memory address of the new Node) to the caller.
    // Without returning a pointer, it would be "returning by value" which just returns a copy and do not make changes to the original linked list, 
    
    Node *newNode = new Node();
    // newNode is a pointer to a Node object.
    // Node* declares a pointer variable named newNode that can hold the memory address of a Node object.
    // 'new' keyword dynamically allocated memory for the new node. 
    // Node() calls the constructor. Initializes the new object.
    // new Node() created a new node.
    // Node *newNode is used to temporarily store the pointer returned by new Node() for further processing, not for creating. 
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode; 
}

// update the original head pointer 
// head --> [10 | 300] --> [20 | 400] --> [30 | NULL]
// 200         200            300            400
void insertAtBeginning (Node* &head, int data) {
    // head is passed by reference, allowing it to modify the original value

    Node *newNode = createNode(data);
    // newNode is a pointer to a new Node structure.
    // newNode --> [5 | NULL]

    newNode->next = head;
    // The new node’s next pointer is set to the current head of the list.
    // newNode --> [5 | *head] (where *head points to the node containing 10)

    head = newNode;
    // Update the head pointer to point to the new node.
    // *head now points to the new node, making it the first node in the list.
    // newNode --> [5 | *] --> [10 | *] --> [20 | *] --> [30 | NULL]

}

void insertAtEnd (Node* &head, int data) {
    Node *newNode = createNode(data);
    
    // If the list is empty, the new node becomes the head.
    // This part can be skipped if it is certained that the list is never empty when calling insertAtEnd().
    // in that case, pass by value would work (Node *head)
    if(head == NULL) {
        head = newNode;
        return;
    } 

    Node *temp = head;
    // temp is used to iterate through the linked list
    // initialized to point to head.
    // ensures that head remains intact.
    // If not used,  the head pointer will point to NULL after traversing is done.  head = head->next;, modifying the head. 
    // access to the start of the list will be lost after the traversal is complete.

    while(temp -> next != NULL) {
        temp = temp -> next;
        // temp = (*temp).next;
        // temp starts pointing to the node that is stored in the 'next' pointer of the current node
        // temp->next is the next pointer of the node that temp is currently pointing to.
    }
    // The loop exits because temp->next == NULL 
    // At this point, temp holds the address to the last node. 
    // temp -> next is NULL. 

    temp -> next = newNode;
    // Replaces the "next" pointer of the last node (NULL) with the memory address of newNode. 

}

void printLinkedList(Node *head){
    Node *temp = head;
    while(temp!=NULL) {
        cout << temp -> data << " ";
        // cout << (*temp).data << " ";
        // similar to head -> data
        temp = temp -> next;
        // The temp pointer is updated to point to the next node in the list.
    } 
    cout << endl;
}


int main() {

    Node *head = NULL;
    // Node* something always means that something is a pointer to a Node object

    // random nodes
    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;

    cout << "INITIAL LINKED LIST: ";
    printLinkedList(head);

    insertAtBeginning(head, 5); 
    cout << "Inserted at Beginning ";
    printLinkedList(head);

    insertAtEnd(head, 35);
    cout << "Inserted at End: ";
    printLinkedList(head);

    return 0;
}


/**
Node *node;
Node *head;
Node *next;
Node *temp;
Node *blabla;
all mean the same thing: a pointer to a Node object.
 */


