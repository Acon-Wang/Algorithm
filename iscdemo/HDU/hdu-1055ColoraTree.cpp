//较难的贪心策略
#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e3+10;
int n,r;

struct 
{
   int c,t,f;
   double w;
}trie[N];

int find(){
    double max=0;//max必须为double
    int pe;
    for(int i=1;i<=n;i++)
        if(trie[i].w>max && i!=r)//pe不能为根节点
    {
        max=trie[i].w;
         pe=i;
    }
    return pe;

}
int main(){
    FASTIO;
    while(cin>>n>>r&&n!=0&&r!=0){

        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>trie[i].c;
            trie[i].t=1;
            trie[i].w=trie[i].c;
            sum+=trie[i].c;
        }
        for(int i=1;i<=n-1;i++){
            int a,b;
            cin>>a>>b;
            trie[b].f=a;
        }

        int res=n;

        while(res>1){
            int pos=find();
            trie[pos].w=0;
            int newf=trie[pos].f;

            sum+=trie[pos].c*trie[newf].t;

            for(int i=1;i<=n;i++)
                if(trie[i].f==pos)
                    trie[i].f=newf;
            
            trie[newf].c=trie[newf].c+trie[pos].c;
            trie[newf].t=trie[newf].t+trie[pos].t;
            trie[newf].w=(double)trie[newf].c/trie[newf].t;
            res--;

        }
        cout<<sum<<endl;
        
    }
    return 0;
}