#include <iostream>
#include <algorithm>

using namespace std;
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
const int N = 1e5;

typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
LL qmi(LL m, LL k, LL p)
{
    LL res = 1 % p, t = m;
    while (k)
    {
        if (k & 1)
            res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
int main()
{
    // FASTIO;
    int p, q, e, l;

    while (~scanf("%d%d%d%d", &p, &q, &e, &l))
    {
        // cin >> p >> q >> e >> l;
        LL x = 0, y = 0;
        LL n = p * q;
        LL f = (p - 1) * (q - 1);
        LL d = exgcd(e, f, x, y);
        x = (x + f) % f;
        for (int i = 1; i <= l; i++)
        {
            LL c;

            scanf("%lld", &c);

            LL m = qmi(c, x, n);

            printf("%c", m);
        }
        printf("\n");
    }
    return 0;
}