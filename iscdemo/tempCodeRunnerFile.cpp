#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
const int N = 1e5;

int a[110];
int f[110][N];
int sum;
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    memset(f,0,sizeof f);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=sum;j++){
            f[i][j]=f[i-1][j]+f[i-1][abs(j-a[i])]+f[i-1][j+a[i]];
            if(f[i][j] < 0) cout << f[i][j] <<endl;
        }
     int ans = 0;
    for (int i = 1; i <=sum;i++)
        if(f[n][i] < 0)ans++;

    cout << ans;
    
    return 0;
}