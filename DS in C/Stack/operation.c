#include <stdio.h>
#include <stdlib.h>
int top = -1;

void push(int head[], int size);
void pop(int array[]);
void peek(int array[]);
void display(int array[]);
void isEmpty(int array[]);
void isFull(int array[], int size);

int main()
{
    int size, option;
    printf("Please,Enter the size of stack :");
    scanf("%d", &size);
    int stack[size];
    while (1)
    {
        printf("Press 1 for push \nPress 2 for pop \nPress 3 for peek\nPress 4 for isEmpty\nPress 5 for isFull\nPress 6 for display\nPress 7 for exit\n");
        printf("Chooose the option :");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push(stack, size);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            peek(stack);
            break;

        case 4:
            isEmpty(stack);
            break;

        case 5:
            isFull(stack, size);
            break;
        case 6:
            display(stack);
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Please,Enter valid choice");
        }
    }

    return 0;
}
/*
Function PUSH(array[], size)   //We declare array and size in main function.
    If top == size - 1 Then   //We declare top as global variable and set top=-1.
        Print "OVERFLOW!"
    Else
        top++        //Increment top by 1
        Print "Enter the element:"
        Read array[top]
        Print "SUCCESSFUL!"
    End If

End Function
*/
void push(int array[], int size)
{
    if (top == size - 1)
    {
        printf("OVERFLOW !\n");
    }
    else
    {
        top++;
        printf("Enter the element :");
        scanf("%d", &array[top]);
        printf("SUCCESSFUL !\n");
    }
}

/*
Function POP(array[])
    If top == -1 Then    //We declare top as global variable and set top=-1.
        Print "UNDERFLOW!"
    Else
        top_element = array[top]
        top--    //Decrement top by 1
        Print "Top element {top_element} is removed."
    End If
     
End Function
*/
void pop(int array[])
{
    int top_element;
    if (top == -1)
    {
        printf("\n UNDERFLOW !\n");
    }
    else
    {
        top_element = array[top];
        top--;
        printf("Top element %d is removed.\n", top_element);
    }
}

/*
FUNCTION Peek(array[])
    IF top == -1 THEN   //We declare top as global variable and set top=-1.
        PRINT "The stack is Empty!"
    ELSE
        PRINT "Top element of stack is array[top]""
    ENDIF
END FUNCTION
*/
void peek(int array[])
{
    if (top == -1)
    {
        printf("The stack is Empty !\n");
    }
    else
    {
        printf("Top element of stack is %d \n", array[top]);
    }
}

/*
FUNCTION display(array[])
    IF top == -1 THEN      //We declare top as global variable and set top=-1.
        PRINT "The stack is Empty!"
    ELSE
        SET ptr = top
        WHILE ptr != -1 
            PRINT array[ptr]
            ptr--      //DECREMENT ptr
        END WHILE
        PRINT newline
    END IF
END FUNCTION
*/
void display(int array[])
{
    if (top == -1)
    {
        printf("The stack is Empty !\n");
    }
    else
    {
        int ptr = top;
        while (ptr != -1)
        {
            printf("%d ", array[ptr]);
            ptr--;
        }
        printf("\n");
    }
}

/*
FUNCTION isEmpty(array[])
    IF top == -1 THEN
        PRINT "The stack is Empty!"
    ELSE
        PRINT "The stack has some elements!"
    END IF
END FUNCTION
*/
void isEmpty(int array[])
{
    if (top == -1)
    {
        printf("The stack is Empty !\n");
    }
    else
    {
        printf("The stack has some elements !\n");
    }
}

/*
FUNCTION isFull(array[], size):
    IF top == size - 1 THEN
        PRINT "Stack is FULL!"
    ELSE
        PRINT "Stack is not FULL. You can enter element."
    END IF
END FUNCTION

*/

void isFull(int array[], int size)
{
    if (top == size - 1)
    {
        printf("Stack is FULL !\n");
    }
    else
    {
        printf("Stack is not FULL.You can enter element.\n");
    }
}