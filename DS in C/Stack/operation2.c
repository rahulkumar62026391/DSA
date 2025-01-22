#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Define the top pointer
struct Node *top = NULL;

/*
FUNCTION push(value)
    // Allocate memory for a new node
     struct Node* newNode = ( struct Node*) malloc(sizeof( struct Node))

    // Check if memory allocation is successful
    IF (newNode == NULL) THEN
        PRINT "Stack overflow (memory allocation failed)."
    ELSE
        // Set the data and link the new node
        Set newNode->data = value
        Set newNode->next = top      //top is global variable
        Set top = newNode

        PRINT value " pushed to stack"
    ENDIF
END FUNCTION
*/

// Function to push an element onto the stack
void push(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack overflow (memory allocation failed).\n");
    }
    else
    {
        newNode->data = value; // Set the data
        newNode->next = top;   // Point to the current top
        top = newNode;         // Update the top pointer
        printf("%d pushed to stack\n", value);
    }
}
/*
FUNCTION pop()
    // Check if the stack is empty
    IF (top == NULL) THEN               //top is global variable
        PRINT "Stack underflow! The stack is empty."
    ELSE
        Set temp = top      // Store the current top node in temp pointer
        Set poppedValue = temp->data // Retrieve the data from the top node
        Set top = top->next       // Update the top pointer to the next node
        free(temp)            // Free memory of the removed node
        PRINT "Popped: " poppedValue
    ENDIF
END FUNCTION
*/

// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow! The stack is empty.\n");
    }
    else
    {
        struct Node *temp = top;      // Store the top node
        int poppedValue = temp->data; // Get the data
        top = top->next;              // Update the top pointer
        free(temp);                   // Free the memory of the popped node
        printf("Popped: %d\n", poppedValue);
    }
}

/*
FUNCTION peek()
    // Check if the stack is empty
    IF (top == NULL) THEN
        PRINT "The stack is empty."
    ELSE
        PRINT "Top element is " top->data
    ENDIF
END FUNCTION
*/
// Function to peek the top element
void peek()
{
    if (top == NULL)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("Top element is %d \n", top->data);
    }
}
/*
FUNCTION isEmpty()
    // Check if the stack is empty
    IF (top == NULL) THEN
        PRINT "The stack is empty."
    ELSE
        PRINT "The stack is not empty."
    ENDIF
END FUNCTION
*/
// Function to check if the stack is empty
void isEmpty()
{
    if (top == NULL)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }
}
/*
FUNCTION display()
    // Check if the stack is empty
    IF (top == NULL) THEN
        PRINT "The stack is empty."
    ELSE
        Set temp = top   // Create a temporary pointer starting at the top
        PRINT "Stack elements: "

        // Traverse through the stack and print each element
        WHILE (temp != NULL)
            PRINT temp->data
            temp = temp->next // Move to the next node
        END WHILE

        PRINT "\n"
    ENDIF
END FUNCTION
*/
// Function to display the stack
void display()
{
    if (top == NULL)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        struct Node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the stack implementation
int main()
{
    push(10);
    push(20);
    push(30);

    peek();
    display();

    pop();
    display();

    pop();
    pop();
    pop(); // Attempt to pop from empty stack

    isEmpty();
    return 0;
}
