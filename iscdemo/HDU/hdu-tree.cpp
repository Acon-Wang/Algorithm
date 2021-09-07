// 树中选择一个子图，使得图中点度数大于K的至多只有一个。求这个子图边权和最大值。

// 思路：
// 裸的换根DP
// 定义f [ i ] [ 0 ]为以i为根节点且所选子树度数和小于等于k-1的最大边权和。
// f [ i ] [ 1 ]为以i为根节点且所选子树度数和小于等于k-1的最大边权和。

// 那么f [ i ] [ 1 ]转移就是取子树最大的前k个f [ v ] [ 0 ] + w值加上，f [ i ] [ 0 ]就是取最大的前k-1个，标记选了哪些点。第二次dfs的时候再考虑父节点过来的贡献，只是需要注意这个点是否被属于父亲的前k大节点。

// 两次dfs就可以把f ff数组给维护出来。
// 注意到题目的还可以允许一个点度数大于k那我们就枚举所有点的f [ u ] [ 1 ]再加上这个点没有选的其他子节点的f [ v ] [ 0 ] + w。结果取最大就好了。

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
int h[N], ne[2 * N], e[2 * N], idx, w[2 * N],du[2*N];
int n, k;
bool st[N];
int f[N][2];
void add(int a, int b, int c)
{

    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dfs(int u)
{
    
    st[u]=true;

    for(int i=h[u];i!=-1;i=ne[i]){
        f[u][0];
    }

}
int main()
{
    FASTIO;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        for (int  i = 0; i < n-1; i++)
        {
           int a,b,c;
           cin>>a>>b>>c;
           add(a,b,c),add(b,a,c);
           du[a]++,du[b]++;
        }

        cout<<dfs(1)<<endl;
    }

    return 0;
}