#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *temp = head;
    struct ListNode *prev = NULL;
    struct ListNode *current;
    struct ListNode *duplicate;

    while (temp != NULL)
    {
        prev = temp;
        current = temp->next;

        while (current != NULL)
        {
            if (temp->val == current->val)
            {
                duplicate = current;
                prev->next = current->next;
                current = current->next;
                free(duplicate);
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;
    struct ListNode *newNode;

    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    head = deleteDuplicates(head);

    printf("Output: ");

    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}
