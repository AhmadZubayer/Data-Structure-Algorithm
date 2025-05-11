#include <iostream>
#include <cstdlib> // For malloc
// This header file provides functions for memory management (like malloc, calloc, realloc, and free) and other utilities.
using namespace std;

struct node {
    int data;
    struct node *link; // for connecting other nodes to transverse
};

int main() {
    struct node *head = NULL; // Correct structure name
    head = (struct node *) malloc(sizeof(struct node)); // Allocate memory dynamically
    head->data = 45; // Assign value to the data field
    // Equivalent Code Without ->: (*head).link = NULL;

    head->link = NULL; //the first node is created, the link is set to NULL, indicating that this is currently the only node in the list.

    cout << head->data << endl; // Print the data
    cout << (*head).data << endl;

    free(head); // Free allocated memory
    return 0;
}
