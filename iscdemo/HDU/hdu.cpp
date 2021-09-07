#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
//#include<pair>
const int N=10;
using namespace std;
typedef pair<int, int> PII;
int n,m,t;
int x1,y1,x2,y2;
char g[N][N];
int d[N][N];

PII q[N*N];

int bfs(){

	int hh=0,tt=0;
	memset(d,-1,sizeof d);
	d[x1][y1]=0;
	q[0]={x1,y1};
	
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	while(hh<=tt){
	
		PII t=q[hh++];
		
		for(int i=0;i<4;i++){
			int x=t.first+dx[i],y=t.second+dy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!='X'&&d[x][y]==-1){
				d[x][y]=d[t.first][t.second]+1;
				q[++tt]={x,y};
			} 
		} 
	}
	return d[x2][y2];

}
int main(){

	
	
    while(cin>>n>>m>>t&&n&&m&&t){
        memset(d,-1,sizeof d);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='S'){
			x1=i,y1=j;
			}
			if(g[i][j]=='D'){
			x2=i,y2=j;
			}
		}
	int res=bfs();
	if(bfs()<=t)cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
    }
    return 0;
}
