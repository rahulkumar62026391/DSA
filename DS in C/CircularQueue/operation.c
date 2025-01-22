#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void enqueue(int array[], int size);
void dequeue(int array[],int size);
void peek(int array[]);
void Rear(int array[]);
void display(int array[],int size);

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
            dequeue(queue,size);
            break;

        case 3:
            peek(queue);
            break;
        case 4:
            Rear(queue);
            break;

        case 5:
            display(queue,size);
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
    IF (rear + 1) MOD size == front THEN       //front and rear is global variables.
        PRINT "Queue is full!"
    ELSE
        IF front == -1 THEN
           Set front = 0
        END IF

        Set rear = (rear + 1) MOD size     //Circular Increment
        PRINT "Enter element:"
        READ value
        Set array[rear] = value
        PRINT "Enqueued" value
    END IF
END FUNCTION

*/
//Function to insert element
void enqueue(int array[], int size){
    int value;
    if ((rear + 1) % size == front) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        if (front == -1) {  // First element
            front = 0;
        }
        rear = (rear + 1) % size;  // Circular increment
        printf("Enter the element :");
        scanf("%d", &value);
        array[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

/*
FUNCTION Dequeue(array[], size)
    IF front == -1 THEN        //front and rear are global variables.
        PRINT "Queue is empty!"
    ELSE
        Set value = array[front]
        IF front == rear THEN
            Set front = -1
            Set rear = -1
        ELSE
            Set front = (front + 1) MOD size  //Circular Increment
        END IF
        PRINT "Dequeued" value
    END IF
END FUNCTION

*/
// Dequeue operation
void dequeue(int array[],int size) {
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        int value = array[front];
        if (front == rear) {  // Queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % size;  // Circular increment
        }
        printf("Dequeued %d\n", value);
    }
}

/*
FUNCTION Peek(array)
    IF front == -1 THEN
        PRINT "Queue is empty!"
    ELSE
        PRINT "Front element is" array[front]
    END IF
END FUNCTION

*/
// Peek the front element
void peek(int array[]){
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is %d\n", array[front]);
    }
}

/*
FUNCTION Peek(array)
    IF front == -1 THEN
        PRINT "Queue is empty!"
    ELSE
        PRINT "Rear element is" array[rear]
    END IF
END FUNCTION

*/
// Peek the rear element
void Rear(int array[]){
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Rear element is %d\n", array[rear]);
    }
}

/*
FUNCTION Display(array, size)
    IF front == -1 THEN   //front and rear are global variables.
        PRINT "Queue is empty!"
    ELSE
        PRINT "Queue elements are:"
        Set i = front
        WHILE (TRUE)
            PRINT array[i]
            IF i == rear THEN
                BREAK  // Stop after displaying the last element
            END IF
            Set i = (i + 1) MOD size  // Circular increment to the next index
        END WHILE
        PRINT a newline
    END IF
END FUNCTION

*/
// Display all elements
void display(int array[],int size) {
   if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (1) {
            printf("%d ", array[i]);
            if (i == rear)
             break;  // Stop after displaying the last element
            i = (i + 1) % size;   // Circular increment
        }
        printf("\n");
    }
}

