//      最近点问题：二维平面中有n（n很大）个点，求出距离最近的两个点

//     思路：因为n的值很大，所以暴力和dp都行不通了吧！分治法就挺好的。
//     将区间一半一半的分开，直到分成只有一个点或两个点的时候！
//     对于只有两个点的区间，最小值就是这两个点的距离，只有一个点的区间，
//     最小值就是无穷大。注意还要考虑合并的时候，可能距离最近的两个点，
//     分别在左右两个不同的区间。对于这种情况的处理如下：
//          mid=(ld+rd)/2;
//          ans = min(solve(ld, mid), solve(mid+1, rd));得到两段区间最小值的最小值
//         从中间向两边寻找，因为我们是按照x坐标排序的，在左区间向左边寻找的时候
//         如果某一个点的x到中间点x的距离大于ans（否则将这样的点保存），那么这个
//         点左边的点就不可能在右区间寻找到相应的点满足两个点的距离小于ans的，那么
//         就结束继续查找（这样算是一种优化）

//         同理在右区间向右寻找。。。

//         然后对存储的节点按照y坐标进行从小到大的排序。
//         枚举每两个点寻找最小的距离
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define x first
#define y second
const int N = 1e5 + 5;
const double MAX = 9999999999999.0;
typedef pair<double, double> PII;

PII nd[100005], ndx[100005];
bool cmp(PII a, PII b)
{
    if (a.x == b.x)
        return a.y<b.y;
    return a.x < b.x;
}
bool cmpy(PII a, PII b)
{
    return a.y < b.y;
}
double dist(PII a, PII b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double QuoitDesigne(int ld, int rd)
{
    if (ld == rd)
        return MAX;
    if (ld + 1 == rd)
        return dist(nd[ld], nd[rd]);
    int mid = (ld + rd) / 2;
    double ans = min(QuoitDesigne(ld, mid), QuoitDesigne(mid + 1, rd));
    int len = 0;
    for (int i = mid; i >= ld; --i)
        if (nd[mid].x - nd[i].x <= ans)
            ndx[len++] = nd[i];
        else
            break;
    for (int i = mid + 1; i <= rd; ++i)
        if (nd[i].x - nd[mid].x <= ans)
            ndx[len++] = nd[i];
        else
            break;

    sort(ndx, ndx + len, cmpy);
    for (int i = 0; i < len - 1; ++i)
        for (int j = i + 1; j < len; ++j)
            if (ndx[j].y - ndx[i].y >= ans)
                break; 
            else
                ans = min(ans, dist(ndx[i], ndx[j]));
    return ans;
}
int main()
{
    FASTIO;
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> nd[i].x >> nd[i].y;
        sort(nd, nd + n, cmp);
        double ans = QuoitDesigne(0, n - 1) / 2.0;
        cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    }
   
}