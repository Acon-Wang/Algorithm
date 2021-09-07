//经典卡特兰数问题
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long LL;
int a[101][101],b[101];
const int N = 200010, mod = 1e9 + 7;

int n;
int fact[N], infact[N];

int ksm(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * ksm(i, mod - 2) % mod;
    }
}

 
void catalan() 
{
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for(i = 2; i <= 100; i++)
    {
        for(j = 0; j < len; j++) 
        a[i][j] = a[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(j = 0; j < len; j++)
        {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry) 
        {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(j = len-1; j >= 0; j--) 
        {
            temp = carry*10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!a[i][len-1])
        len --;
        b[i] = len;
    }
}
int main() {
    // init();
    catalan();
    while(cin>>n){

        for(int i=b[n];i>0;i--)
            cout<<a[n][i-1];
        cout<<endl;
    }
   
    // int res = (LL)fact[2 * n] * infact[n] % mod * infact[n] % mod * ksm(n + 1, mod - 2) % mod;
    
    return 0;
}
