#include <cstdio>
#include <list>

struct LNode
{
    int data;
    LNode*next;
};

void push_back(LNode*&head,const int val)
{
    LNode*node = new LNode;
    node->data = val;
    node->next = NULL;
    if (!head)
    {
        head = node;
    }
    LNode*temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }

    temp ->next = node;
}

int main()
{
    LNode*head = new LNode;
    head->data = 0;
    head->next = NULL;

    push_back(head,10);
    push_back(head,20);

    LNode*temp = head;
    while (temp)
    {
        printf("%d\n",temp->data);
        temp = temp ->next;
    }
    return 0;
}