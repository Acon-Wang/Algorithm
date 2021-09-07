// 将每个值转化为这个值的所有奇质因数的幂次和加上这个值是否为2的倍数，然后进行nim博弈即可
#include<iostream>
#include<cstring >
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int p[maxn], cnt;
int flag[maxn];

void prime()
{
    for(int i = 2; i < maxn; i++)
    {
        if(!flag[i]) p[cnt++] = i;
        for(int j = 0; p[j] < maxn / i; j++)
        {
            flag[p[j] * i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}

int sg(int x)
{
    int res = 0;
    for(int i = 0; i < cnt && p[i] <= x / p[i]; i++)
    {
        if(x % p[i] == 0)
        {
            if(p[i] == 2)
            {
                res++;
                while(x % p[i] == 0)
                    x /= p[i];
            }
            else
            {
                while(x % p[i] == 0)
                    x /= p[i], res++;
            }
        }
    }
    if(x > 1) res++;
    return res;

}

int main()
{
    prime();
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            res ^= sg(x);
        }
        printf("%s\n", res ? "W" : "L");
    }
}
