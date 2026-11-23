#include <stdbool.h>

bool isPalindrome(struct ListNode* head)
{
    int a[100000];
    int n = 0;
    int i, j;

    struct ListNode* temp = head;

    while (temp != NULL)
    {
        a[n] = temp->val;
        n++;
        temp = temp->next;
    }

    i = 0;
    j = n - 1;

    while (i < j)
    {
        if (a[i] != a[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
