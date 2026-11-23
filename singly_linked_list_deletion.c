#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create linked list
void create()
{
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

// Delete first element
void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("First element deleted\n");
    }
}

// Delete specified element
void deleteSpecified()
{
    struct Node *temp, *prev;
    int key;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
    }
    else if (prev == NULL)
    {
        head = head->next;
        free(temp);
        printf("Element deleted\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Element deleted\n");
    }
}

// Delete last element
void deleteLast()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Last element deleted\n");
    }
    else
    {
        temp = head;
        prev = NULL;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);

        printf("Last element deleted\n");
    }
}

// Display linked list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        printf("Linked List: ");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create");
        printf("\n2. Delete First");
        printf("\n3. Delete Specified Element");
        printf("\n4. Delete Last");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

