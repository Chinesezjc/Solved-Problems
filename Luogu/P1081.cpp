//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[100005], nxt[2][100005], v, cnt, ans, s, x;
pair<int, int> anss;
class multiply
{
public:
    pair<int, int> Val;
    int To;
} NXT[20][100005];
map<int, int> tmp;
pair<int, int> g[4];
inline bool cmp(const pair<int, int> &A, const pair<int, int> &B)
{
    return abs(A.first - v) == abs(B.first - v) ? A.first < B.first : abs(A.first - v) < abs(B.first - v);
}
inline int CMP(const pair<int, int> &A, const pair<int, int> &B)
{
    if (A.second == 0)
    {
        if (B.second == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (B.second == 0)
        {
            return -1;
        }
    }
    double l = B.first * 1.0 / B.second, r = A.first * 1.0 / A.second;
    if (l < r)
    {
        return 1;
    }
    if (l > r)
    {
        return -1;
    }
    return 0;
}
inline pair<int, int> operator+(const pair<int, int> &A, const pair<int, int> &B)
{
    return {A.first + B.first, A.second + B.second};
}
inline bool operator<=(const pair<int, int> &A, const int &B)
{
    return A.first + A.second <= B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n; i; --i)
    {
        v = a[i];
        map<int, int>::iterator now = tmp.insert({a[i], i}).first;
        int j = 2;
        cnt = 0;
        while (j--)
        {
            if (now != tmp.begin())
            {
                --now;
            }
            else
            {
                break;
            }
            g[cnt++] = *now;
        }
        j = 2;
        now = tmp.find(a[i]);
        while (j--)
        {
            if (++now != tmp.end())
            {
                g[cnt++] = *now;
            }
            else
            {
                break;
            }
        }
        sort(g, g + cnt, cmp);
        nxt[1][i] = g[0].second;
        nxt[0][i] = g[1].second;
    }
    for (int i = 1; i <= n; ++i)
    {
        NXT[0][i] = {{abs(a[i] - a[nxt[0][i]]), abs(a[nxt[0][i]] - a[nxt[1][nxt[0][i]]])},
                     nxt[1][nxt[0][i]]};
        // cout << NXT[0][i].Val.first << ' ' << NXT[0][i].Val.second << ' ' << NXT[0][i].To << endl;
    }
    for (int i = 1; 1 << i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            NXT[i][j] = {NXT[i - 1][j].Val + NXT[i - 1][NXT[i - 1][j].To].Val,
                         NXT[i - 1][NXT[i - 1][j].To].To};
            // cout << NXT[i][j].Val.first << ' ' << NXT[i][j].Val.second << ' ' << NXT[i][j].To << endl;
        }
    }
    cin >> x;
    anss.first = INF;
    for (int i = 1; i <= n; ++i)
    {
        s = i;
        pair<int, int> ANS;
        for (int j = 19; j >= 0; --j)
        {
            if (ANS + NXT[j][s].Val <= x && NXT[j][s].To)
            {
                ANS = ANS + NXT[j][s].Val;
                s = NXT[j][s].To;
            }
        }
        if (nxt[0][s] && ANS <= x - abs(a[nxt[0][s]] - a[s]))
        {
            ANS.first += abs(a[nxt[0][s]] - a[s]);
            s = nxt[0][s];
        }
        if (ANS.second == 0)
        {
            ANS.first = INF;
        }
        // cout << ANS.first << ' ' << ANS.second << ' ' << s << endl;
        if (CMP(anss, ANS) == 1)
        {
            anss = ANS;
            ans = i;
        }
        else if (CMP(anss, ANS) == 0 && a[i] > a[ans])
        {
            anss = ANS;
            ans = i;
        }
    }
    cout << ans << endl;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> s >> x;
        pair<int, int> ANS;
        for (int j = 19; j >= 0; --j)
        {
            if (ANS + NXT[j][s].Val <= x && NXT[j][s].To)
            {
                ANS = ANS + NXT[j][s].Val;
                s = NXT[j][s].To;
            }
        }
        if (nxt[0][s] && ANS <= x - abs(a[nxt[0][s]] - a[s]))
        {
            ANS.first += abs(a[nxt[0][s]] - a[s]);
            s = nxt[0][s];
        }
        cout << ANS.first << ' ' << ANS.second << endl;
    }
    return 0;
}