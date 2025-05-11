#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    // a pointer to another Node object
};

void printLinkedList(Node *head){
    Node *temp = head;
    // temp is used to iterate through the linked list
    // initialized to point to head.
    // ensures that head remains intact.
    // If not used,  the head pointer will point to NULL after traversing is done.  head = head->next;, modifying the head. 
    // access to the start of the list will be lost after the traversal is complete.
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
    Node *head = new Node();  
    //Creates a new Node dynamically and assigns its address to the pointer head.
    //  stores the address of the first node in the list.
    // [10 | *] -> [20 | *] -> [30 | NULL]
    // The head pointer points to the first node ([10 | *]).
    head -> data = 10;
    // (*head).data = 45;
    // Assigns the value 45 to the data field of the node pointed to by head.
    head -> next = NULL;
    // (*head).next = NULL;
    // not required for controlled examples like this. 
    // Required when new nodes may be added later.
    // Sets the next pointer of the node pointed to by head to NULL, indicating it is the last node (for now).


    Node *node2 = new Node();
    // Represents the second node in the linked list.
    node2 -> data = 20;
    node2 -> next = NULL;

    cout << "Initial Linked List:" << endl;
    printLinkedList(head);
    
    head -> next = node2;
    // forms a chain 
    // link the first node (head) to the second node (node2) in the linked list.
    // Without this connection, the "next" of the previous node would point to NULL and would terminate after the last node. 

    cout << "Linked List with the second node:" << endl;
    printLinkedList(head);


    Node *node3 = new Node();
    // Represents the third node in the linked list.
    node3 -> data = 30;
    node3 -> next = NULL;
    node2 -> next = node3;

    cout << "LINKED  LIST" << endl;
    printLinkedList(head);

     return 0;

}