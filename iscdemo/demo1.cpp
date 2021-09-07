#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
const int N = 1e6 + 10;
int n, m, c;
struct
{
    int l, r;
    int max;
} tr[N * 4];
int a[N];
void pushup(int u)
{
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}
void build(int u, int l, int r)
{

    if (l == r)
    {
        tr[u] = {l, r, c};
        // return;
    }
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modifiy(int u, int a)
{
    if (tr[u].l == tr[u].r)
    {
        // if (tr[u].max >= a)
        tr[u].max -= a;
        // return;
    }
    else
    {

        if (tr[u << 1].max >= a)
            modifiy(u << 1, a);
        else if (tr[u << 1 | 1].max >= a)
            modifiy(u << 1 | 1, a);
        pushup(u);
    }
}
int query(int u, int id)
{
    if (tr[u].l == tr[u].r)
        return tr[u].max;
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (id <= mid)
        return query(u << 1, id);
    else
        return query(u << 1 | 1, id);
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        int ans1 = 0, ans2 = 0;

        for (int i = 1; i <= n; i++)
            modifiy(1, a[i]);

        for (int i = 1; i <= n; i++)
        {
            if (query(1, i) == c)
            {
                ans1 = i - 1;
                break;
            }
            if (i == n)
            {
                ans1 = n;
            }
        }
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            auto p = mp.lower_bound(a[i]);
            if (p != mp.end())
            {
                p->second--;
                mp[p->first - a[i]]++;
                if (p->second == 0)
                    mp.erase(p);
            }
            else
            {
                mp[c - a[i]]++;
                ans2++;
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}