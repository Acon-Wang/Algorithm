#include<iostream>
#include<cstring >
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+100;
 
vector<int>node[N];
 
int main()
{

    int w;
    cin>>w;
    while(w--)
    {
        int n,k;
        
        scanf("%d%d",&n,&k);
        int limit=2*n*(1<<k);
        for(int i=1;i<=limit;i++)
            node[i].clear();
        for(int i=1;i<=limit;i++)
        {
            int num;
            scanf("%d",&num);
            node[i].push_back(num);
        }
        int mid=1;
        while(k--)
        {
            
            mid=mid+limit>>1;
            for(int j=mid+1;j<=limit;j++)
            {
                int pos=mid-(j-(mid+1));
                reverse(node[pos].begin(),node[pos].end());
                node[j].insert(node[j].begin(),node[pos].begin(),node[pos].end());
                node[pos].clear();
            }
        }
        bool first=true;
        for(int i=limit-2*n+1;i<=limit;i++)
            for(int j=0;j<node[i].size();j++)
            {
                if(first)
                    first=false;
                else
                    putchar(' ');
                printf("%d",node[i][j]);
            }
        puts("");
    }
 
 
    return 0;
}
