#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;
queue<string> q;
unordered_map<string, int> d;
unordered_map<string, string> ans;
string bfs(string state)
{

    q.push(state);
    d[state] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char op[4] = {'u', 'r', 'd', 'l'};

    string end = "12345678x";

    string cnt = "";
    while (q.size())
    {
        auto t = q.front();
        auto tc = t;

        q.pop();
        if (t == end)
            return ans[t];
        //if(d[t]>=50)return "unsolvable";
        int distance = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a * 3 + b], t[k]);
                if (!ans.count(t))
                {
                    d[t] = distance + 1;
                    ans[t] = ans[tc] + op[i];
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
        }
    }
}

int main()
{

    string bin;
    while (getline(cin, bin))
    {

        string g, c, seq;

        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i] == ' ')
                continue;
            g += bin[i];
            if (bin[i] == 'x')
                seq += bin[i];
        }

        int t = 0;
        for (int i = 0; i < seq.size(); i++)
            for (int j = i + 1; j < seq.size(); j++)
                if (seq[i] > seq[j])
                    t++;

        if (t % 2)
            puts("unsolvable");
        else
            cout << bfs(g) << endl;
    }
    return 0;
}