#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int main()
{
    char s[3000];
    int a;
    get_primes(N);
    while (~scanf("%s%d", s, &a) && a)
    {
  
        for (int i = 0; i < cnt; i++)
        {
            int n = primes[i];
            // cout<<n<<" ";
            if (n >= a)
            {
                cout << "GOOD" << endl;
                break;
            }
            int m = 0;
            for (int j = 0; s[j]; j++)
                m = ((m * 10) + (s[j] - '0')) % n;
            if (m == 0)
            {
                cout << "BAD"
                     << " " << n << endl;
                break;
            }
        }
    }

    return 0;
}