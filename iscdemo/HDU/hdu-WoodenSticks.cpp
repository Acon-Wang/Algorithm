#include<iostream>
#include<string>
#include<algorithm>
#define FASTIO  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=5005;

struct node{
    int l,w;
}a[N];

bool cmp(node a ,node b){
    if(a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}
int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i].l>>a[i].w;
        sort(a,a+n,cmp);
        int flag;
        int ans=1;
        int l[N],w[N];
        l[0]=a[0].l;
        w[0]=a[0].w;
        for(int i=1;i<n;i++){
            flag=0;
            for(int j=0;j<ans;j++){
                if(a[i].l>=l[j]&&a[i].w>=w[j]){
                    l[j]=a[i].l;
                    w[j]=a[i].w;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                l[ans]=a[i].l;
                w[ans]=a[i].w;
                ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}