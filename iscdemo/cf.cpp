#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
using namespace std;
#define limit (10000 + 5)//防止溢出
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f3f
#define lowbit(i) i&(-i)//一步两步
#define EPS 1e-9
#define FASTIO  ios::sync_with_stdio(false);cin.tie(0);
#define ff(a) printf("%d\n",a );
#define pi(a,b) pair<a,b>
#define rep(i, a, b) for(ll i = a; i <= b ; ++i)
#define per(i, a, b) for(ll i = b ; i >= a  ; --i)
#define MOD 998244353
#define traverse(u) for(int i = head[u]; ~i ; i = edge[i].next)
// #define FOPEN freopen("C:\\Users\\tiany\\CLionProjects\\akioi\\data.txt", "rt", stdin)
// #define FOUT freopen("C:\\Users\\tiany\\CLionProjects\\akioi\\dabiao.txt", "wt", stdout)
#define debug(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
inline ll read(){
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
    ll sign = 1, x = 0;char s = getchar();
    while(s > '9' || s < '0' ){if(s == '-')sign = -1;s = getchar();}
    while(s >= '0' && s <= '9'){x = (x << 3) + (x << 1) + s - '0';s = getchar();}
    return x * sign;
#undef getchar
}//快读
void print(ll x) {
    if(x/ 10) print(x / 10);
    *O++=x % 10+'0';
}
void write(ll x) {
    if(x < 0)putchar('-'),x = -x;
    print(x);
    fwrite(obuf,O-obuf,1,stdout);
    O = obuf;
}
int main(){

    cout<<"hello,wolrd"<<endl;
  
    return 0;
}