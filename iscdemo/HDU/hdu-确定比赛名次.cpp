
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1100;
int h[N], ne[N], e[N], idx;
int d[N];

int n, m;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void topsort()
{

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            heap.push(i);
        }
    }
    int flag=0;
    while (heap.size())
    {

        auto t = heap.top();
        if(!flag){
            cout<<t;
            flag=1;
        }
        else cout << " "<<t;
        heap.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
                heap.push(j);
        }
    }
    cout << endl;
}
int main()
{
    while (cin >> n >> m)
    {   
        idx=0;
        for (int i = 1; i <= n; i++)
            h[i] = -1;
        // cin >> n >> m;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            add(a, b);
            d[b]++;
        }
        topsort();
    }
    return 0;
}