#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int maxn = 5000 + 7;

ll dp[maxn][maxn], f[maxn], cnt[maxn], ans[maxn], sum[maxn];
ll fac[maxn], inv[maxn];

ll qpow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll C(ll n, ll m)
{
    if (m > n || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n < k + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("1");
                if (i != n)
                    printf(" ");
            }
            printf("\n");
            continue;
        }
        if (n % (k + 1) == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("0");
                if (i != n)
                    printf(" ");
            }
            printf("\n");
            continue;
        }
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                dp[i][j] = 0;
            }
            f[i] = sum[i] = cnt[i] = ans[i] = 0;
        }
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j + k <= n - i - 1)
                {
                    dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % mod;
                }
                if (j > 0)
                {
                    dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j] * j % mod) % mod;
                }
            }
        }

        ll SUM = 0;          //总方案
        int r = n % (k + 1); //最后剩下的数字
        for (int i = 1; i <= n; i++)
        {                          //前i个数都被删掉了
            int j = n - i - r + 1; //可以进行的删除次数
            f[i] += dp[i - 1][j] * fac[j] % mod * C(n - i, j) % mod;
            f[i] %= mod;

            cnt[i] += dp[i - 1][j] * fac[j] % mod * C(n - i - 1, j) % mod;
            cnt[i] %= mod;

            sum[i] = (sum[i - 1] + cnt[i]) % mod;
            SUM = (SUM + f[i]) % mod;
            ans[i] = (f[i] + sum[i - 1]) % mod;
        }
 
       
        SUM = qpow(SUM, mod - 2);
        for (int i = 1; i <= n; i++)
        {
            printf("%lld", ans[i] * SUM % mod);
            if (i != n)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
