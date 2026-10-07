#include <stdio.h>

#define MAX 5

int front = -1;
int rear = -1;
int queue[MAX];

void insert()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);

        if (front == -1)
            front = 0;

        rear = rear + 1;
        queue[rear] = item;

        printf("Element inserted successfully\n");
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        front = front + 1;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf(" Queue Menu \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Exiting\n");
            break;
        }
        else
        {
            printf("Enter a valid choice\n");
        }
    }

    return 0;
}

