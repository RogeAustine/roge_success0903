#include <cstdio>
#include <queue>
#include <vector>


struct TNode
{
    int data;
    TNode*lchild;
    TNode*rchild;
};

void push_left(TNode*&root,int val)
{
    TNode*node = new TNode;
    node->data = val;
    node->lchild = NULL;
    node->rchild = NULL;

    if (!root)
    {
        root = node;
    }

    if (root->lchild == NULL)
    {
        push_left(root->lchild,val);
    }
    else if (root->rchild == NULL)
    {
        push_left(root->rchild,val);
    }
    else 
    {
        TNode*temp = root->lchild;
        push_left(temp,val);
    }
    // 不JB玩了

}

TNode* add_left(TNode*&parent,int val)
{
    TNode*node = new TNode;
    node->data = val;
    node->lchild = nullptr;
    node->rchild = nullptr;

    if (!parent)
    {
        parent = node;
        return node;
    }

    if (parent->lchild == NULL)
    {
        parent->lchild = node;
        return node;
    }
    else if (parent->rchild == NULL)
    {
        parent ->rchild = node;
        return node;
    }
    else 
    {
        return parent;
    }
}

TNode* add_right(TNode*&parent,int val)
{
    TNode*node = new TNode;
    node->data = val;
    node->lchild = nullptr;
    node->rchild = nullptr;

    if (!parent)
    {
        parent = node;
        return node;
    }

    if (parent->rchild == NULL)
    {
        parent->rchild = node;
        return node;
    }
    else if (parent->lchild == NULL)
    {
        parent ->lchild = node;
        return node;
    }
    else 
    {
        return parent;
    }
}

void preorder(TNode*root)
{
    if (!root)
    {
        return;
    }
    preorder(root->lchild);
    printf("%d\n",root->data);
    preorder(root->rchild);
}

void midorder(TNode*root)
{
    if (!root)
    {
        return;
    }
    printf("%d\n",root->data);
    midorder(root->lchild);
    midorder(root->rchild);
}

void postorder(TNode*root)
{
    if (!root)
    {
        return;
    }
    postorder(root->rchild);
    printf("%d\n",root->data);
    postorder(root->lchild);
}

void layorder(TNode*root)
{
    if (!root)
    {
        return;
    }
    std::queue<TNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        TNode*node = q.front();
        q.pop();
        printf("%d\n",node->data);
        if (node->lchild) q.push(node->lchild);
        if (node->rchild) q.push(node->rchild);
    }
}


int main()
{
    TNode*root = new TNode;
    root ->data = 0;
    root->rchild = NULL;
    root->lchild = NULL;    

    TNode*one = add_left(root,1);
    TNode*two = add_right(root,2);

    TNode*three = add_left(one,3);
    TNode*four = add_right(one,4);

    TNode*five = add_left(two,5);
    TNode*six = add_right(two,6);

    // preorder(root); 
    // midorder(root);
    // postorder(root);
    layorder(root);
    
    return 0;
}