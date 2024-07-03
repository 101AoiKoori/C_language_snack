#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *Next;
} ListNode;

ListNode *head, *tail, *p;

int main()
{
    int a[5] = {2, 4, 6, 8, 10};

    head = (ListNode *)malloc(sizeof(ListNode));
    if (head == NULL)
    {
        fprintf(stderr, "内存开辟失败\n");
        return 1;
    }
    head->Next = NULL;

    tail = head;


    for (int i = 0; i < 5; ++i)
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        if (p == NULL)
        {
            fprintf(stderr, "内存开辟失败\n");
            ListNode *temp = head;
            while (temp != NULL)
            {
                ListNode *next = temp->Next;
                free(temp);
                temp = next;
            }
            return 1;
        }
        p->val = a[i];
        p->Next = NULL;
        tail->Next = p; 
        tail = p;      
    }

    p = head->Next; 
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->Next;
    }
    printf("\n");

    p = head;
    while (p != NULL)
    {
        ListNode *next = p->Next;
        free(p);
        p = next;
    }

    return 0;
}
