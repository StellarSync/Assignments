// LinkedList implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Functions to insert a node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Put in the data
    new_node->data = new_data;

    // Link the old list off the new node
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the LinkedList

void
printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
  struct
  Node* head = NULL; // Start with empty list
  
  // Insert some nodes  at the beginning
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 4);

  printf("Created Linked List: ");
  printList(head);

  return 0;
}
