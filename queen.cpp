#include <cstdio>

void solve()
{

}
int main()
{
    int n = 0;
    scanf("%d",&n);

    // 创建数组
    int count = 0;
    bool queen[n][n] = {0};

    // 放置皇后
    for (int i = 0; i < n; i++)
    {
        queen[0][i] = true;
        for (int j = 0;j <n;j++)
        {
            queen[1][j] = true;
        }
    }
    return 0;
}

// vector
// std::vector<vector<bool>>queen;