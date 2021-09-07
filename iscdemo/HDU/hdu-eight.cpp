#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

string s;
string e = "12345678x";
unordered_map<string,int> dist;
unordered_map<string,pair<char,string> > pre;

int dx[4] = {-1,1,0,0},dy[4]={0,0,-1,1};
char op[4] = {'u','d','l','r'};

int get(string str)
{
    for(int i=0;i<str.size();i++)
        if(str[i] == 'x')
            return i;
    return -1;
}

bool bfs(){

    queue<string> q;

    q.push(s);

    dist[s] = 0;

    while(q.size())
    {
        string t = q.front();
        q.pop();
        if(t==e) return true;
        int p = get(t);
        int d = dist[t];
        int x = p/3 , y = p%3;

        string temp = t;
        for(int i=0;i<4;i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {
                t = temp;
                swap(t[3*a+b],t[3*x+y]);
                if(dist.count(t)==0)
                {
                    dist[t] = d + 1;
                    pre[t] = {op[i],temp};
                    q.push(t);
                }
            }
        }

    }

    return false;
}

int main(){

  string bin;
   while(getline(cin,bin)){
    
    string g, c, seq;

    for(int i=0;i<bin.size();i++){
        if(bin[i] ==' ')continue;
        s +=bin[i];
        if (bin[i] == 'x') seq += bin[i];

    }
    if(!bfs()) cout<<"unsolvable"<<endl;
    else {

        string res;
        while(e!=s)
        {
            res += pre[e].first;
            e = pre[e].second;
        }
        reverse(res.begin(),res.end());
        cout << res << endl;
    }


   }
    return 0;

}

