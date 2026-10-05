
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int TOP = -1;
int stack[MAX];

void push(int data)
{
    if (TOP == MAX - 1)
    {
        printf("STACK IS OVERFLOW\n");
        return;
    }

    TOP++;
    stack[TOP] = data;
}

int pop()
{
    int value;

    if (TOP == -1)
    {
        printf("STACK IS UNDERFLOW\n");
        return -1;
    }

    value = stack[TOP];
    TOP--;

    return value;
}

void display()
{
    if (TOP == -1)
    {
        printf("STACK IS EMPTY\n");
        return;
    }

    printf("ELEMENTS IN THE STACK ARE:\n");

    for (int i = TOP; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, data, value;

    while (1)
    {
        printf("\nSTACK MENU DRIVEN OPERATIONS\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("ENTER A CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("ENTER ELEMENT TO ADD INTO THE STACK: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                value = pop();

                if (value != -1)
                {
                    printf("POPPED VALUE = %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("EXITED\n");
                exit(0);

            default:
                printf("INVALID CHOICE\n");
        }
    }

    return 0;
}
