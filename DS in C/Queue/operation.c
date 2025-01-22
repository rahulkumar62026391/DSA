#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void enqueue(int array[], int size);
void dequeue(int array[]);
void peek(int array[]);
void Rear(int array[]);
void display(int array[]);

int main()
{
    int size, option;
    printf("Please,Enter the size of queue : ");
    scanf("%d", &size);
    int queue[size];
    while (1)
    {
        printf("\nPress 1 for insert \nPress 2 for delete \nPress 3 for front element\nPress 4 for rear element\nPress 5 for display all element\nPress 6 for exit\n");
        printf("Chooose the option  :");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            enqueue(queue, size);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            peek(queue);
            break;
        case 4:
            Rear(queue);
            break;

        case 5:
            display(queue);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nPlease,Enter valid choice");
        }
    }
    return 0;
}

/*
FUNCTION Enqueue(array[], size)
    IF rear == size - 1 THEN
        PRINT "Queue is full"
    ELSE
        IF front == -1 OR front > rear THEN
            Set front = 0
        END IF

        Set rear = rear + 1
        PRINT "Enter the element:"
        READ value
        Set array[rear] = value
        PRINT "Enqueued" value
    END IF
END FUNCTION

*/

// Function to enqueue an element into the queue
void enqueue(int array[], int size)
{
    int value;
    if (rear == size - 1)
    {
        printf("Queue is full! Cannot enqueue.\n");
    }
    else
    {

        if (front == -1 || front > rear)
        {
            front = 0; // Initialize front if the queue was empty
        }
        rear++;
        printf("Enter the element :");
        scanf("%d", &value);
        array[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

/*
FUNCTION Dequeue(array[])
    IF front == -1 OR front > rear THEN
        PRINT "Queue is empty! Cannot dequeue."
    ELSE
        Set value = array[front]  // Get the front element
        Set front = front + 1     // Move front to the next position

        IF front > rear THEN
            Set front = -1        // Reset the queue when empty
            Set rear = -1
        END IF

        PRINT "Dequeued" value
    END IF
END FUNCTION

*/

// Function to dequeue an element from the queue
void dequeue(int array[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty! Cannot dequeue.\n");
    }
    else
    {

        int value = array[front];
        front++;
        if (front > rear)
        {
            // Reset the queue when it becomes empty
            front = -1;
            rear = -1;
        }
        printf("Dequeued %d\n", value);
    }
}

/*
FUNCTION Peek(array[])
    IF front == -1 OR front > rear THEN
        PRINT "Queue is empty!"
    ELSE
        PRINT "Element at frontend is", array[front]
    END IF
END FUNCTION

*/
//Functioin to print front element
void peek(int array[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("\nElement at frontend is %d\n", array[front]);
    }
}

/*
FUNCTION Rear(array[])
    IF front == -1 OR front > rear THEN
        PRINT "Queue is empty!"
    ELSE
        PRINT "Element at backend is", array[rear]
    END IF
END FUNCTION
*/
//Function to print rear element
void Rear(int array[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!s\n");
    }
    else
    {
        printf("\nElement at backend is %d\n", array[rear]);
    }
}
/*
FUNCTION Display(array[])
    IF front == -1 OR front > rear THEN
        PRINT "Queue is empty!"
    ELSE
        FOR i = front TO rear
            PRINT "Element at position", i + 1, "is", array[i]
        END FOR
    END IF
END FUNCTION
*/

//Function to display element in the Queue
void display(int array[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\nElement at position %d is %d\n", i + 1, array[i]);
        }
    }
}