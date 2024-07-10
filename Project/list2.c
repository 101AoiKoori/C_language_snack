#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

// 创建一个新的链表节点
ListNode *createNode(int value)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 链表相加函数
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 创建一个虚拟头节点
    ListNode dummyHead;
    dummyHead.next = NULL;
    ListNode *current = &dummyHead;
    int carry = 0;

    // 遍历两个链表
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;                     // 计算进位
        current->next = createNode(sum % 10); // 创建新节点
        current = current->next;
    }

    return dummyHead.next; // 返回结果链表的头节点
}

// 打印链表函数
void printList(ListNode *node)
{
    while (node != NULL)
    {
        printf("%d", node->val);
        if (node->next != NULL)
        {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

// 主函数测试
int main()
{
    // 创建示例链表 l1 = [2,4,3]
    ListNode *l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // 创建示例链表 l2 = [5,6,4]
    ListNode *l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // 计算链表相加
    ListNode *result = addTwoNumbers(l1, l2);

    // 打印结果链表
    printList(result);

    // 释放链表内存
    // 需要遍历并释放链表的每个节点

    return 0;
}
