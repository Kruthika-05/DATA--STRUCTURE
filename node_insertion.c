#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create linked list
void create(struct Node **head)
{
    struct Node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(*head == NULL)
            *head = newnode;
        else
        {
            temp = *head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

// Insert at front
void insertFront(struct Node **head)
{
    struct Node *newnode;

    newnode = malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = *head;
    *head = newnode;
}

// Insert at end
void insertEnd(struct Node **head)
{
    struct Node *newnode, *temp;

    newnode = malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(*head == NULL)
        *head = newnode;
    else
    {
        temp = *head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

// Insert at specified position
void insertPosition(struct Node **head, int position)
{
    struct Node *newnode, *temp;
    int i;

    if(position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(position == 1)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    temp = *head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, position;

    while(1)
    {
        printf("\n1. Create");
        printf("\n2. Insert at Front");
        printf("\n3. Insert at End");
        printf("\n4. Insert at Position");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create(&head);
                break;

            case 2:
                insertFront(&head);
                break;

            case 3:
                insertEnd(&head);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(&head, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

