#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
const int N=1010;
using namespace std;

string a[N];
string add(const string& A, const string& B)
{
    string C;
    int t = 0;
    for (int i = A.size()-1, j = B.size()-1; i >= 0 || j >= 0 || t > 0; i--, j--)
    {
        if (i >= 0) t += (A[i] - '0');
        if (j >= 0) t += (B[j] - '0');
        C += ((t % 10) + '0');
        t /= 10;
    }

    reverse(C.begin(), C.end());
    return C;
}

void f(int n){

    for(int i=5;i<=n;i++)
    {
        a[i]=add(add(a[i-4],a[i-2]),a[i-1]);
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    a[0]="1";
    a[1]="1";
    a[2]="2";
    a[3]="4";
    a[4]="7";
    f(1000);
    while(cin>>n){

        if(n>4)cout<<a[n]<<endl;
        else cout<<a[n]<<endl;
    }

    return 0;

}