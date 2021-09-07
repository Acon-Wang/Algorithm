

#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

const int N = 500;
int a[N + 1], b[N + 1], dp[N + 1];

int lcis(int n, int m)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[j] = max(dp[j], dp[k] + 1);
            else if (a[i] > b[j])
            {
                if (dp[k] < dp[j])
                    k = j;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int main(void)
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        printf("%d\n", lcis(n, m));
        if (t)
            printf("\n");
    }

    return 0;
}
