#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int value)
{
    // Create a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    { // If list is empty
        *head = new_node;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    // Traverse to the end
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
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
    Set head = head->next  // Move head to the next node

    // Step 4: Free the memory of the old head node
    Free temp  // Deallocate the memory of the old head node

    // Step 5: Print success message
    Print "Node at the beginning deleted."
End Function
*/

// Function to delete the node at the beginning of the list
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

    // Step 4: Free the memory of the old head node
    free(temp);

    // Step 5: Print success message
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

    // Step 3: Traverse the list to find the second-to-last node
    Set temp = head
    While temp->next is not NULL and temp->next->next is not NULL do
        Set temp = temp->next  // Move temp to the next node

    // Step 4: Delete the last node
    Set lastNode = temp->next  // Get the last node
    Set temp->next = NULL  // Set the second-to-last node's next to NULL
    Free lastNode  // Free the memory of the last node
    Print "Node at the end deleted."
End Function
*/

// Function to delete the node at the end of the list
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
        *head = NULL; // Set head to NULL since the list is now empty
        printf("Node at the end deleted.\n");
        return;
    }

    // Step 3: Traverse the list to find the second-to-last node
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Step 4: Delete the last node
    struct Node *lastNode = temp->next;
    temp->next = NULL; // Set the second-to-last node's next to NULL
    free(lastNode);    // Free the memory of the last node
    printf("Node at the end deleted.\n");
}

/*
Function deleteAtPosition(head, position)
    // Step 1: Check if the list is empty
    If head is NULL then
        Print "The list is empty."
        Return

    // Step 2: Handle deletion of the first node (position 1)
    If position is 1 then
        Set temp = head  // Store the current head node for deletion
        Set head = head->next  // Move head to the next node
        Free temp  // Deallocate memory for the old head node
        Print "Node at position", position, "deleted."
        Return

    // Step 3: Traverse the list to find the node before the one to delete
    Set temp = head
    Set count = 1

    While temp is not NULL and count < position - 1 do
        Set temp = temp->next  // Move to the next node
        Increment count by 1

    // Step 4: Check if the position is out of bounds
    If temp is NULL or temp->next is NULL then
        Print "Position", position, "is out of bounds."
        Return

    // Step 5: Delete the node at the given position
    Set nodeToDelete = temp->next  // The node to delete
    Set temp->next = temp->next->next  // Bypass the node to delete
    Free nodeToDelete  // Free memory of the deleted node
    Print "Node at position", position, "deleted."

End Function
*/

// Function to delete the node at a given position in the linked list
void deleteAtPosition(struct Node **head, int position)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Step 2: Handle deletion of the first node (position 1)
    if (position == 1)
    {
        struct Node *temp = *head;
        *head = (*head)->next; // Move head to the next node
        free(temp);            // Free the memory of the old head
        printf("Node at position %d deleted.\n", position);
        return;
    }

    // Step 3: Traverse the list to find the node before the one to be deleted
    struct Node *temp = *head;
    int count = 1;

    // Loop to find the previous node of the node to be deleted
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Step 4: If the position is out of bounds
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // Step 5: Delete the node at the given position
    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next; // Bypass the node to be deleted
    free(nodeToDelete);            // Free the memory of the deleted node
    printf("Node at position %d deleted.\n", position);
}

void traverse(struct Node *head)
{
    struct Node *temp = head; // Start at the heads
    printf("Linked list: ");
    while (temp != NULL)
    {                                 // Loop until the end of the list
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

int main()
{

    struct Node *head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);

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
