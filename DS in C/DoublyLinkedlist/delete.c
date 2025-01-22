#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert at the end
void insertAtEnd(struct Node** head, int value) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    

    struct Node* last = *head;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Insert the new node after the last node
    last->next = new_node;
    new_node->prev = last;
    printf("Inserted %d at the end.\n", value);
}


/*
Function deleteAtBeginning(head)
    // Step 1: Check if the list is empty
    If head is NULL then
        Print "The list is empty."
        Return

    // Step 2: Store the current head node
    Set temp = head  // Store the current head node for later deletion

    // Step 3: Update the head pointer to the next node
    Set head = head->next  // Move the head pointer to the next node

    // Step 4: If the new head is not NULL, update its prev pointer to NULL
    If head is not NULL then
        Set head->prev = NULL  // Set the prev pointer of the new head to NULL

    // Step 5: Free the memory of the old head node
    Free temp  // Deallocate the memory of the old head node

    // Step 6: Print success message
    Print "Node at the beginning deleted."
End Function
*/

// Function to delete at the beginning of the list
void deleteAtBeginning(struct Node **head)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Step 2: Store the current head node
    struct Node *temp = *head;

    // Step 3: Update the head pointer to the next node
    *head = (*head)->next;

    // Step 4: If the new head is not NULL, update its prev pointer to NULL
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    // Step 5: Free the memory of the old head node
    free(temp);

    // Step 6: Print success message
    printf("Node at the beginning deleted.\n");
}

/*
Function deleteAtEnd(head)
    // Step 1: Check if the list is empty
    If head is NULL then
        Print "The list is empty."
        Return

    // Step 2: If there is only one node in the list
    If head->next is NULL then
        Free head  // Free the only node
        Set head = NULL  // Set head to NULL as the list is now empty
        Print "Node at the end deleted."
        Return

    // Step 3: Traverse the list to find the last node
    Set temp = head
    While temp->next is not NULL 
        Set temp = temp->next  // Move temp to the next node

    // Step 4: Update the previous node's next pointer to NULL
    Set temp->prev->next = NULL  // Set the previous node's next to NULL

    // Step 5: Free the memory of the last node
    Free temp  // Deallocate the memory of the last node

    // Step 6: Print success message
    Print "Node at the end deleted."
End Function
*/

// Function to delete at the end of the list
void deleteAtEnd(struct Node **head)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Step 2: If there is only one node
    if ((*head)->next == NULL)
    {
        free(*head);  // Free the only node
        *head = NULL; // Set head to NULL as the list is now empty
        printf("Node at the end deleted.\n");
        return;
    }

    // Step 3: Traverse the list to find the last node
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Step 4: Update the previous node's next pointer to NULL
    temp->prev->next = NULL;

    // Step 5: Free the memory of the last node
    free(temp);

    // Step 6: Print success message
    printf("Node at the end deleted.\n");
}

/*
Function deleteAtPosition(head, position)
    // Step 1: Check if the list is empty
    If head is NULL then
        Print "The list is empty."
        Return

    // Step 2: If position is 1, delete the first node
    If position is 1 then
        Set temp = head
        Set head = head->next  // Move head to the next node
        If head is not NULL then
            Set head->prev = NULL  // Update the prev pointer of the new head
        Free temp  // Free the memory of the old head
        Print "Node at position 1 deleted."
        Return

    // Step 3: Traverse the list to find the node at the given position
    Set temp = head
    Set count = 1

    // Traverse until we reach the node at the given position
    While temp is not NULL and count is less than position 
        Set temp = temp->next
        Increment count

    // Step 4: If position is out of bounds
    If temp is NULL then
        Print "Position is out of bounds."
        Return

    // Step 5: Delete the node at the given position
    If temp->next is not NULL then
        Set temp->next->prev = temp->prev  // Update the next node's prev pointer
    If temp->prev is not NULL then
        Set temp->prev->next = temp->next  // Update the previous node's next pointer

    // Step 6: Free the memory of the node
    Free temp

    // Step 7: Print success message
    Print "Node at position deleted."
End Function
*/

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Step 2: If position is 1, delete the first node
    if (position == 1)
    {
        struct Node *temp = *head;
        *head = (*head)->next; // Move head to the next node
        if (*head != NULL)
        {
            (*head)->prev = NULL; // Update the prev pointer of the new head
        }
        free(temp); // Free the memory of the old head
        printf("Node at position %d deleted.\n", position);
        return;
    }

    // Step 3: Traverse the list to find the node at the given position
    struct Node *temp = *head;
    int count = 1;

    // Traverse until we reach the node to delete
    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    // Step 4: If the position is out of bounds
    if (temp == NULL)
    {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // Step 5: Delete the node at the given position
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev; // Update the next node's prev pointer
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next; // Update the previous node's next pointer
    }

    // Step 6: Free the memory of the node
    free(temp);

    // Step 7: Print success message
    printf("Node at position %d deleted.\n", position);
}

// Function to print the list
void traverse(struct Node *head)
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    traverse(head);

    deleteAtBeginning(&head);

    traverse(head);

    deleteAtEnd(&head);

    traverse(head);

    deleteAtPosition(&head, 2);

    traverse(head);

    deleteAtPosition(&head, 11);

    traverse(head);

    return 0;
}
