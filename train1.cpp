#include <iostream>
#include <cassert>


struct LNode
{
    int data;
    LNode*next;
};

void push_front(LNode**head,int val)
{
    if (*head == NULL)
    {
        LNode*node = new LNode;
        node->data = val;
        node->next = nullptr;
        *head = node;
    }
    else
    {
        LNode*node = new LNode;
        node->data = val;
        node->next = *head;
        *head = node;
    }
}

void push_back(LNode**head,int val)
{
    if (*head == NULL)
    {
        LNode*node = new LNode;
        node->data = val;
        node->next = nullptr;
        *head = node;
    }
    else 
    {
        // To reach at the tail
        LNode*temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }

        // 
        LNode*node = new LNode;
        node->data = val;
        node->next = nullptr;
        temp->next = node;     
    }
}

LNode* invert(LNode*head)
{
    if (!head)
    {
        return NULL;
    }
    LNode*pre = NULL;
    LNode*temp = head;
    while (temp)
    {
        LNode*post = temp->next;
        temp->next = pre;
        pre = temp;
        temp = post;
    }
    return pre;
}

void invert_n_to_m(LNode*head,int n,int m)
{ 
    // gpt思路
    if (!head||n>=m||n < 0) return;

    LNode*dummy = new LNode;
    dummy->next = head;
    LNode*pre = dummy;

    for (int i = 0;i < n;i++)
    {
        if (!pre->next) return;
        pre = pre->next;
    }

    LNode*cur = pre->next;
    for (int j = 0;j < m-n;j++)
    {
        if (!cur||pre->next)    return;
        LNode*move = cur->next;
        cur->next = move->next;
        move->next = pre->next;
        pre->next = move;
    }

    head = dummy->next;
}

int main()
{
    LNode*head = new LNode;
    head->data = 20;
    head->next = nullptr;

    push_front(&head,10);
    push_front(&head,0);
    push_back(&head,30);
    push_back(&head,40);
    head = invert(head);
    // Try let's try.

    invert_n_to_m(head,2,4);

    LNode*temp = head;
    while (temp)  // ??????But it isn't right!
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }

    // Before you return,I'm thirsty for a several hours' break.................😭😭😭😭😭😭😭😭😭😭😭
    return 0;
}