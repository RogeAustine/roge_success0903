#include <cstdio>
#include <vector>
#include <queue>

#define VEX 5
struct Graph_List
{
    int data;
    std::vector<Graph_List*>next;
};

void add_edge(Graph_List*&a,Graph_List*&b)
{
    if (!a||!b)
    {
        return;
    }

    a->next.push_back(b);
    b->next.push_back(a);
}

void delete_edge(Graph_List*&a,Graph_List*&b)
{
    if (!a||!b)
    {
        return;
    }
    // std::replace(a->next.begin(),a->next.end(),b,NULL);
    // std::replace(b->next.front(),b->next.back(),a,NULL);    

}

void bfs(Graph_List*&start)
{
    if (!start)
    {
        return;
    }
    std::vector<bool>visited(VEX,false);
    std::queue<Graph_List*>q;
    q.push(start);
    visited[start->data] = true;
    // Actually the order can be replaced by....dict or list

    while (!q.empty())
    {
        Graph_List*temp = q.front();
        q.pop();

        printf("%d\n",temp->data);
        for (auto neighbor : temp->next)
        {
            if (!visited[neighbor->data])
            {
                q.push(neighbor);
                visited[neighbor->data] = true;
            }
        }
    }
    printf("\n");
}

void dfs(Graph_List*&start)
{
    if (!start)
    {
        return;
    }
    
}
int main()
{
    Graph_List*a = new Graph_List;
    Graph_List*b = new Graph_List;
    Graph_List*c = new Graph_List;
    Graph_List*d = new Graph_List;
    Graph_List*e = new Graph_List;
    
    a->data = 0;
    b->data = 1;
    c->data = 2;
    d->data = 3;
    e->data = 4;
    
    a->next.push_back(b);
    a->next.push_back(e);
    a->next.push_back(d);
    a->next.push_back(c);
    b->next.push_back(c);
    c->next.push_back(d);
    b->next.push_back(a);
    e->next.push_back(a);
    d->next.push_back(a);
    d->next.push_back(c);
    c->next.push_back(a);
    c->next.push_back(b);

    bfs(a);

    return 0;

}