#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
FUNCTION insertAtBeginning(struct Node** head, int data)
    // Step 1: Create a new node
    CREATE newNode
    SET newNode->data = data

    // Step 2: Check if the list is empty
    IF *head IS NULL THEN
        SET newNode->next = newNode  // Point to itself to form a circular link
        SET *head = newNode          // Update head to the new node
    ELSE
        // Step 3: Find the last node
        CREATE temp = *head
        WHILE temp->next != *head DO
            SET temp = temp->next
        END WHILE

        // Step 4: Insert newNode at the beginning
        SET newNode->next = *head
        SET temp->next = newNode
        SET *head = newNode          // Update head to the new node
    END IF

    // Step 5: Print success message
    PRINT "Inserted " + data + " at the beginning."
END FUNCTION
*/
// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

/*
FUNCTION insertAtEnd(struct Node** head, int data)
    // Step 1: Create a new node
    CREATE newNode
    SET newNode->data = data

    // Step 2: Check if the list is empty
    IF *head IS NULL THEN
        SET newNode->next = newNode  // Point to itself to form a circular link
        SET *head = newNode          // Update head to the new node
    ELSE
        // Step 3: Find the last node
        CREATE temp = *head
        WHILE temp->next != *head DO
            SET temp = temp->next
        END WHILE

        // Step 4: Insert newNode at the end
        SET temp->next = newNode
        SET newNode->next = *head    // Complete the circular link
    END IF

    // Step 5: Print success message
    PRINT "Inserted " + data + " at the end."
END FUNCTION
*/
// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Inserted %d at the end.\n", data);
}

/*
FUNCTION deleteAtBeginning(struct Node** head)
    // Step 1: Check if the list is empty
    IF *head IS NULL THEN
        PRINT "The list is empty."
        RETURN
    END IF

    // Step 2: Store the current head node
    CREATE temp = *head

    // Step 3: Check if there is only one node
    IF (*head)->next == *head THEN
        SET *head = NULL       // Update head to NULL as the list becomes empty
        FREE temp              // Free the single node
    ELSE
        // Step 4: Find the last node in the list
        CREATE last = *head
        WHILE last->next != *head DO
            SET last = last->next
        END WHILE

        // Step 5: Update head and adjust pointers
        SET *head = (*head)->next  // Move head to the next node
        SET last->next = *head     // Update the last node to point to the new head
        FREE temp                  // Free the memory of the old head node
    END IF

    // Step 6: Print success message
    PRINT "Node at the beginning deleted."
END FUNCTION
*/
// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if ((*head)->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
    printf("Node at the beginning deleted.\n");
}

/*
FUNCTION deleteAtEnd(struct Node** head)
    // Step 1: Check if the list is empty
    IF *head IS NULL THEN
        PRINT "The list is empty."
        RETURN
    END IF

    // Step 2: Store the current head node
    CREATE temp = *head

    // Step 3: Check if there is only one node
    IF (*head)->next == *head THEN
        SET *head = NULL       // Update head to NULL as the list becomes empty
        FREE temp              // Free the single node
    ELSE
        // Step 4: Traverse to the last node
        CREATE prev = NULL
        WHILE temp->next != *head DO
            SET prev = temp
            SET temp = temp->next
        END WHILE

        // Step 5: Update the second-to-last node's next pointer
        SET prev->next = *head  // Adjust the second-to-last node to point to head
        FREE temp               // Free the memory of the last node
    END IF

    // Step 6: Print success message
    PRINT "Node at the end deleted."
END FUNCTION
*/
// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if ((*head)->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
    printf("Node at the end deleted.\n");
}

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

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    display(head);

    // Delete nodes
    deleteAtBeginning(&head);
    display(head);
    deleteAtEnd(&head);
    display(head);

    // More operations
    deleteAtEnd(&head);
    deleteAtEnd(&head);
    deleteAtEnd(&head); // Trying to delete from an empty list
    display(head);

    return 0;
}
