#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

/*
FUNCTION insertAtBeginning(head, value)
BEGIN
    // Step 1: Allocate memory for a new node
    new_node = ALLOCATE memory for Node;   // struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Step 2: Assign value to the new node
    new_node->data = value;
    new_node->next=NULL

    if (*head == NULL) { // If list is empty
        *head = new_node;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    // Step 3: Point the new node to the current head
    new_node->next = *head;

    // Step 4: Update the head pointer to the new node
    *head = new_node;

    // Step 5: Print success message
    PRINT "Inserted", value, "at the beginning.";
END FUNCTION
*/

void insertAtBeginning(struct Node** head, int value) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next=NULL;
    if (*head == NULL) { // If list is empty
        *head = new_node;
        printf("Inserted %d at the beginning.\n", value);
        return;
    }
    new_node->next = *head;
    *head = new_node;
    printf("Inserted %d at the beginning.\n", value);
}

/*
FUNCTION insertAtEnd(head, value)
BEGIN
    // Step 1: Allocate memory for a new node
    new_node = ALLOCATE memory for Node;   //struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Assign the value to the new node
    new_node->data = value;
    new_node->next = NULL;  // This will be the last node

    // Step 3: If the list is empty, set head to the new node
    IF *head IS NULL THEN
        *head = new_node;
        PRINT "Inserted", value, "at the end.";
        RETURN;
    END IF

    // Step 4: Traverse to the last node
    temp = *head;
    WHILE temp->next IS NOT NULL DO
        temp = temp->next;
    END WHILE

    // Step 5: Link the new node at the end
    temp->next = new_node;
    PRINT "Inserted", value, "at the end.";
END FUNCTION
*/

void insertAtEnd(struct Node** head, int value) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) { // If list is empty
        *head = new_node;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    // Traverse to the end
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    printf("Inserted %d at the end.\n", value);
}

/*
FUNCTION insertAtPosition(head, value, position)
BEGIN
    // Step 1: Allocate memory for a new node
    new_node = ALLOCATE memory for Node;  // struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;

    // Step 2: Check if the position is 1 (insert at the beginning)
    IF position IS 1 THEN
        new_node->next = *head;
        *head = new_node;
        PRINT "Inserted", value, "at position", position;
        RETURN;
    END IF

    // Step 3: Traverse to the node just before the position
    temp = *head;
    count = 1;
    WHILE temp IS NOT NULL AND count < position - 1 
        temp = temp->next;
        count = count + 1;
    END WHILE

    // Step 4: Check if the position is out of bounds
    IF temp IS NULL THEN
        PRINT "Position", position, "is out of bounds.";
        FREE new_node;
        RETURN;
    END IF

    // Step 5: Insert the new node at the specified position
    new_node->next = temp->next;
    temp->next = new_node;
    PRINT "Inserted", value, "at position", position;
END FUNCTION
*/

void insertAtPosition(struct Node** head, int value, int position) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next=NULL;

    if (position == 1) { // Insert at the beginning
        new_node->next = *head;
        *head = new_node;
        printf("Inserted %d at position %d.\n", value, position);
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    // Traverse to the position
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        free(new_node);
        return;
    }

    // Insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d.\n", value, position);
}

/*
FUNCTION traverse(head)
BEGIN
    // Step 1: Start at the head of the list
    temp = head;
    
    // Step 2: Print the linked list
    PRINT "Linked list: ";
    
    // Step 3: Traverse through the list
    WHILE temp IS NOT NULL 
        PRINT temp->data, "->";
        temp = temp->next;
    END WHILE

    // Step 4: Indicate the end of the list
    PRINT "NULL";
END FUNCTION
*/

// Function to traverse the linked list
void traverse(struct Node* head) {
    struct Node* temp = head; // Start at the heads
    printf("Linked list: ");
    while (temp != NULL) { // Loop until the end of the list
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

int main(){
  struct Node* head=NULL;

  insertAtBeginning(&head,5);
  insertAtBeginning(&head,10);
  insertAtBeginning(&head,15);
  insertAtBeginning(&head,20);
  insertAtBeginning(&head,25);

  traverse(head);

  insertAtEnd(&head,30);
  insertAtEnd(&head,35);

  traverse(head);  

  insertAtPosition(&head,100,1);
  insertAtPosition(&head,0,7);

  traverse(head);  

  insertAtPosition(&head,1000,11);

  traverse(head);

    return 0;
}