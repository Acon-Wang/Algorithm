//线段树的单点修改（简单）
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;

const int N = 100010;
int m, p;
struct Node
{
    int l, r;
    int v;
} tr[N * 4];
void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void pushup(int u)
{
    // tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));
    return v;
}
void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v ++;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
int main()
{


    int n;
   
    while(cin>>n&&n){
        // memset(tr,0,sizeof tr);
        for(int i=1;i<=4*n;i++){
            tr[i].v=0;
        }
        build(1,1,n);
        for(int j=1;j<=n;j++){
        int a,b;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            modify(1,i,1);
        }
        }
        for(int i=1;i<=n;i++){
            cout<<query(1,i,i)<<" ";
        }
        cout<<endl;
    }
    // int m, p;
    // int n = 0;
    // int last = 0;
    // cin >> m >> p;
    // build(1, 1, m);
    // while (m--)
    // {
    //     int x;
    //     char op[2];
    //     cin >> op >> x;
    //     if (*op == 'Q')
    //     {
    //         last = query(1, n - x + 1, n);
    //         cout << last << endl;
    //     }
    //     else
    //     {
    //         modify(1, n + 1, (last + x) % p);
    //         n++;
    //     }
    // }

    return 0;
}