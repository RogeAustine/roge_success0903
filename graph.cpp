#include <cstdio>
#include <queue>


#define VEX 8
struct Graph_Vector
{
    char data[VEX];
    bool edge[VEX][VEX];
    bool visited[VEX];
};

void add_edge(Graph_Vector*g,size_t a,size_t b)
{
    if (!g)
    {
        return;
    }
    if (g->edge[a-1][b-1])
    {
        return;
    }
    g->edge[a-1][b-1] = 1;
}

void delete_edge(Graph_Vector*g,size_t a,size_t b)
{
    if (!g)
    {
        return;
    }
    if (g->edge[a-1][b-1] == 0)
    {
        g->edge[a-1][b-1] = 1;
    }
}

void BFS(Graph_Vector *g)
{
    if (!g)
    {
        return;
    }

    std::queue<size_t>q;
    for (int i = 0;i < VEX;i++)
    {
        if (g->visited[i] == 0)
        {
            q.push(i);
        }
    }
    
}

void DFS(Graph_Vector*g)
{
    if (!g)
    {
        return;
    }
}
int main()
{

    return 0;
}