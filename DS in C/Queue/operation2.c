#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Define the front and rear pointers for the queue
struct Node *front = NULL;
struct Node *rear = NULL;

/*
FUNCTION Enqueue(value)
    // Allocate memory for the new node
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node))
    
    // Check if memory allocation is successful
    If newNode == NULL
        Print "Queue overflow (memory allocation failed)"
    Else
        // Set the data and next pointer for the new node
        Set newNode->data = value
        Set newNode->next = NULL
        
        If rear == NULL
            // The queue is empty, so both front and rear should point to the new node
            Set front = newNode
            Set rear = newNode
        Else
            // Add the new node to the end of the queue and update rear
            rear->next = newNode
            rear = newNode
        
        Print value "enqueued to queue"
    End If
End FUNCTION
*/

// Function to enqueue an element
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue overflow (memory allocation failed).\n");
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL)
        {
            // If the queue is empty, both front and rear point to the new node
            front = rear = newNode;
        }
        else
        {
            // Add the new node at the end and update rear
            rear->next = newNode;
            rear = newNode;
        }
        printf("%d enqueued to queue\n", value);
    }
}

/*
Function Dequeue()
    If front == NULL
        Print "Queue underflow! The queue is empty."
    Else
        Set dequeuedValue = front->data
        Set temp = front   // Store the front in temp pointer
        Set front = front->next

        If front == NULL
            Set rear = NULL
        EndIf

       // Free memory of temp
        free(temp)
        Print "Dequeued dequeuedValue from queue"
    EndIf
End Function
*/
// Function to dequeue an element
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow! The queue is empty.\n");
    }
    else
    {
        int dequeuedValue = front->data;
        struct Node *temp = front;
        front = front->next;

        // If the queue becomes empty, update rear to NULL
        if (front == NULL)
        {
            rear = NULL;
        }

        free(temp);
        printf("Dequeued %d from queue\n", dequeuedValue);
    }
}

/*
Function Peek
    If front == NULL
        Print "The queue is empty."
    Else
        Print "Front element is front->data"
    EndIf
End Function
*/
// Function to display the front element
void peek()
{
    if (front == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("Front element is %d\n", front->data);
    }
}

/*
Function Rear
    If rear == NULL
        Print "The queue is empty."
    Else
        Print "Rear element is rear->data"
    EndIf
End Function
*/
// Function to display the rear element
void Rear()
{
    if (rear == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("Rear element is %d\n", rear->data);
    }
}

/*
Function isEmpty
    If front == NULL
        Print "The queue is empty."
    Else
        Print "The queue is not empty."
    EndIf
End Function
*/
// Function to check if the queue is empty
int isEmpty()
{

    if (front == NULL)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The stack is not empty.\n");
    }
}

/*
Function Display
    If front == NULL
        Print "The queue is empty."
    Else
        Set temp = front  // Store the front in temp pointer
        Print "Queue elements: "
        While temp != NULL
            Print temp->data
            Set temp = temp->next
        EndWhile
        Print newline
    EndIf
End Function
*/
//Function to display element in queue
void display()
{
    if (front == NULL)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the queue implementation
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();
    dequeue();
    display();
    peek();

    dequeue();
    dequeue();

    // Try to dequeue from an empty queue
    dequeue();
    display();
    return 0;
}
