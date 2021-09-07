//方法一：bfs连通块
//方法二：并查集
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 55;
char c[N][N];
int p[N * N];
bool st[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//上右下左

struct
{
    int r;
    int l;
    int u;
    int d;
} block[11];
void init()
{
    block[0] = {1, 0, 1, 0};
    block[1] = {0, 1, 1, 0};
    block[2] = {1, 0, 0, 1};
    block[3] = {0, 1, 0, 1};
    block[4] = {0, 0, 1, 1};
    block[5] = {1, 1, 0, 0};
    block[6] = {1, 1, 1, 0};
    block[7] = {1, 0, 1, 1};
    block[8] = {1, 1, 0, 1};
    block[9] = {0, 1, 1, 1};
    block[10] = {1, 1, 1, 1};
}
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// bool check(int x, int y)
// {

//     if (block[x].d + block[y].u == 2 || block[x].l + block[y].r == 2 || block[x].r + block[y].l == 2 || block[x].u + block[y].d == 2)
//         return true;
//     else
//         return false;
// }
void bfs(int x, int y)
{
    //st[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m)
        {
            int t2 = c[a][b] - 'A';
            int t1 = c[x][y] - 'A';

            if (!st[a][b])
            {
               
                if (i==0&&block[t1].u+block[t2].d==2)
                {

                    st[a][b] = true;
                    bfs(a, b);
                }
                 if (i==1&&block[t1].l+block[t2].r==2)
                {

                    st[a][b] = true;
                    bfs(a, b);
                }
                   if (i==2&&block[t1].d+block[t2].u==2)
                {

                    st[a][b] = true;
                    bfs(a, b);
                }
                   if (i==3&&block[t1].r+block[t2].l==2)
                {

                    st[a][b] = true;
                    bfs(a, b);
                }
            }
        }
    }
}
int main()
{
    init();
    while (cin >> n >> m && n != -1 && m != -1)

    {

        memset(st, false, sizeof st);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }

        // int num = n * m;

        // for (int i = 0; i < num; i++)
        //     p[i] = i;
        int res = 0;
        // st[0][0]=true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!st[i][j])
                {
                    st[i][j] = true;
                    bfs(i, j);
                    res++;
                }
            }
        cout << res << endl;
    }

    return 0;
}