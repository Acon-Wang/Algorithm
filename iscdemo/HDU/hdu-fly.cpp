#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>
#include<map>
#define FASTIO  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    int t;
    FASTIO;

    while(cin>>t){ 

        map<string,int>ans;
        while(t--){
           string s;
           cin>>s;
           ans[s]++;
        }
        int maxn=0;
        for(auto i:ans){

            maxn=max(maxn,i.second);
        }
        if(t==0)cout<<'0'<<endl;
        else cout<<maxn<<endl;

    }


    return 0;

}

