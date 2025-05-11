#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void deleteFirstNode(Node *&head) {
    if (head == NULL) {
        return;
    }
    Node *temp = head;    
    head = head -> next;
    delete(temp);

}

void deleteLastNode(Node *&head);

void printLinkedList(Node *head) {
    Node *temp = head;
    while(temp  != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;

    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;

    cout << "Linked List: " ;
    printLinkedList(head);

    cout << "After Deleting the first Node: ";
    deleteFirstNode(head);
    printLinkedList(head);


}