
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5+10;
#define FASTIO  ios::sync_with_stdio(false);cin.tie(0);
int h[N], ne[N], e[N], idx;
int d[N];
int ans[N];
int n, m;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void topsort()
{

    priority_queue<int> heap;

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            heap.push(i);
        }
    }
   
    int id=1;
    while (heap.size())
    {

        auto t = heap.top();
        ans[id++]=t;
        heap.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
                heap.push(j);
        }
    }
     for(int i=n; i>=1; i--)
        if(i!=1)
           cout<<ans[i]<<" ";
        else
           cout<<ans[i]<<endl;
}
int main()
{   
    FASTIO;
    int t;
    cin>>t;
    while (t--)
    {   
       
        cin>>n>>m;
        idx=0;
        for (int i = 1; i <= n; i++)
            h[i] = -1;
        // cin >> n >> m;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            add(b, a);
            d[a]++;
        }
       
        topsort();
    }
    return 0;
}