#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/*
Function insertAtBeginning(Node** head, int value)
    // Step 1: Create a new node
    Node* newNode = (Node*) malloc(sizeof(Node))
    newNode->data = value

    // Step 2: Check if the list is empty
    If (*head == NULL) Then
        newNode->next = newNode // Point to itself
        *head = newNode
        Return

    // Step 3: Traverse to the last node
    Node* temp = *head
    While (temp->next != *head)
        temp = temp->next

    // Step 4: Update pointers
    newNode->next = *head
    temp->next = newNode
    *head = newNode // Update head to the new node

   Print("Inserted %d at the beginning.\n", value);
End Function
*/

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        // If list is empty, point newNode to itself
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head; // New node points to the head
        temp->next = newNode;  // Last node points to new node
        *head = newNode;       // Update head to new node
    }
    printf("Inserted %d at the beginning.\n", value);
}

/*
Function insertAtEnd(Node** head, int value)
    // Step 1: Create a new node
    Node* newNode = (Node*) malloc(sizeof(Node))
    newNode->data = value

    // Step 2: Check if the list is empty
    If (*head == NULL) Then
        newNode->next = newNode // Point to itself
        *head = newNode
        Return

    // Step 3: Traverse to the last node
    Node* temp = *head
    While (temp->next != *head)
        temp = temp->next

    // Step 4: Update pointers
    temp->next = newNode
    newNode->next = *head

     Print("Inserted %d at the end.\n", value);
End Function
*/

// Function to insert at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        // If list is empty, point newNode to itself
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;  // Last node points to new node
        newNode->next = *head; // New node points to head
    }
    printf("Inserted %d at the end.\n", value);
}

/*
Function insertAtPosition(Node** head, int value, int position)
    // Step 1: Create a new node
    Node* newNode = (Node*) malloc(sizeof(Node))
    newNode->data = value

    // Step 2: Handle invalid positions
    If (position <= 0) Then
        Print "Invalid position"
        Return

    // Step 3: Insert at the beginning if position is 1
    If (position == 1) Then
        Call insertAtBeginning(head, value)
        Return

    // Step 4: Traverse to the desired position
    Node* temp = *head
    int count = 1
    While (count < position - 1 AND temp->next != *head)
        temp = temp->next
        count++

    // Step 5: Check for out-of-bounds position
    If (temp->next == *head AND count != position - 1) Then
        Print "Position out of bounds"
        Return

    // Step 6: Update pointers to insert the new node
    newNode->next = temp->next
    temp->next = newNode

     Print("Inserted %d at position %d.\n", value, position);
End Function
*/
// Function to insert at a specific position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    
    if (position <= 0) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1 && temp->next == *head) {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next; // New node points to the next node
    temp->next = newNode;       // Previous node points to new node
    printf("Inserted %d at position %d.\n", value, position);
}


/*
Function display(Node* head)
    // Step 1: Check if the list is empty
    If (head == NULL) Then
        Print "The list is empty"
        Return

    // Step 2: Traverse the list and print nodes
    Node* temp = head
    Print "Circular Linked List: "
    Do
        Print temp->data + " -> "
        temp = temp->next
    While (temp != head)
    Print "(head)"
End Function
*/
// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);

    insertAtBeginning(&head, 5);
    display(head);

    insertAtPosition(&head, 15, 3);
    display(head);

    return 0;
}
