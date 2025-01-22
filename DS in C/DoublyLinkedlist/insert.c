#include <stdio.h>
#include <stdlib.h>

// Structure for a node in doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/*
Function insertAtBeginning(head, value)
{
    // Step 1: Create a new node
    new_node = AllocateMemoryForNode()   // struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value               // Set the data of the new node to the given value
    new_node->next = head                // Set the new node's next pointer to the current head
    new_node->prev = NULL                // Set the new node's prev pointer to NULL

    // Step 2: If the list is not empty, update the previous pointer of the current head node
    If head is not NULL
    {
        head->prev = new_node           // Set the prev pointer of the current head to point to the new node
    }

    // Step 3: Move head to point to the new node
    head = new_node                      // Set the head pointer to the new node

    // Step 4: Print success message
    Print "Inserted", value, "at the beginning."
}
*/

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

     // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        printf("Inserted %d at the beginning.\n", value);
        return;
    }
    
     new_node->next = *head;
     (*head)->prev = new_node;
    // Move head to point to the new node
    *head = new_node;
    printf("Inserted %d at the beginning.\n", value);
}

/*
Function insertAtEnd(head, value)
{
    // Step 1: Create a new node
    new_node = AllocateMemoryForNode()  //  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value              // Set the data of the new node to the given value
    new_node->next = NULL               // Set the new node's next pointer to NULL (since it will be the last node)

    // Step 2: If the list is empty, make the new node the head
    If head is NULL
    {
        new_node->prev = NULL           // Set the prev pointer of the new node to NULL
        head = new_node                 // Set head to the new node (since the list was empty)
        Print "Inserted", value, "at the end."
        Return
    }

    // Step 3: Traverse to the last node
    last = head
    While last->next is not NULL
    {
        last = last->next               // Move to the next node until reaching the last one
    }

    // Step 4: Insert the new node after the last node
    last->next = new_node               // Set the current last node's next pointer to the new node
    new_node->prev = last               // Set the new node's prev pointer to the current last node
    Print "Inserted", value, "at the end."
}
*/

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
Function insertAtPosition(head, value, position)
{
    // Step 1: Check if the position is valid
    If position <= 0
    {
        Print "Invalid position."
        Return

    // Step 2: Create a new node
    new_node = AllocateMemoryForNode()  // struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value             // Set the data of the new node

    // Step 3: If position is 1, insert at the beginning
    If position == 1
    {
        new_node->next = head           // Set the new node's next pointer to the current head
        new_node->prev = NULL           // Set the new node's prev pointer to NULL
        If head is not NULL
        {
            head->prev = new_node       // Set the current head node's prev pointer to the new node
        }
        head = new_node                 // Set the head pointer to the new node
        Print "Inserted", value, "at position", position
        Return
    }

    // Step 4: Traverse the list to find the node before the given position
    temp = head
    count = 1
    While temp is not NULL and count < position - 1
    {
        temp = temp->next              // Move to the next node
        count = count + 1
    }

    // Step 5: Check if the position is out of bounds
    If temp is NULL
    {
        Print "Position", position, "is out of bounds."
        Return

    // Step 6: Insert the new node at the given position
    new_node->next = temp->next       // Set the new node's next pointer to the next node of temp
    new_node->prev = temp             // Set the new node's prev pointer to the temp node

    // Step 7: Update the next node's prev pointer if the new node is not inserted at the end
    If temp->next is not NULL
    {
        temp->next->prev = new_node    // Set the next node's prev pointer to the new node
    }

    // Step 8: Update the current node's next pointer to point to the new node
    temp->next = new_node

    // Step 9: Print success message
    Print "Inserted", value, "at position", position
}
*/

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int value, int position) {
    // If position is invalid
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
     new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    

    // If the position is 1, insert at the beginning
    if (position == 1) {
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        printf("Inserted %d at position %d.\n", value, position);
        return;
    }
    struct Node* temp = *head;
    int count = 1;

    // Traverse the list to find the previous node of the given position
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If position is out of bounds
    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    // Insert the new node after the temp node
    new_node->next = temp->next;
    new_node->prev = temp;

    // If the new node is not inserted at the end
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;

    printf("Inserted %d at position %d.\n", value, position);
}

/*
Function traverse(head)
    // Step 1: Initialize a temporary pointer to the head of the list
    Set temp = head

    // Step 2: Print the header for the list display
    Print "Doubly Linked List: "

    // Step 3: Traverse through the entire list
    While temp is not NULL 
        // Print the current node's data followed by "<->"
        Print temp->data followed by " <-> "
        
        // Move the temporary pointer to the next node
        Set temp = temp->next
    End While

    // Step 4: After the loop, print "NULL" to indicate the end of the list
    Print "NULL"
End Function
*/

// Function to print the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes at different positions
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    traverse(head);

    insertAtEnd(&head, 30);
    insertAtEnd(&head,40);

    traverse(head);

    insertAtPosition(&head, 25, 3);

    traverse(head);

   insertAtPosition(&head,100,11);


    traverse(head);

    return 0;
}
