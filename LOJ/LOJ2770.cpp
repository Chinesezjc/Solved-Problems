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
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int cases;
string S, T;
int s[1000005], t[1000005], sums[1000005], sumt[1000005], lg[1000005], ST[20][1000005], cnts, cntt;
bool ss[1000005], tt[1000005], ans;
int lowbit(int now)
{
    return now & -now;
}
int MAX(int A, int B)
{
    return s[A] >= s[B] ? A : B;
}
int query(int L, int R)
{
    int len = lg[R - L + 1];
    return MAX(ST[len][L], ST[len][R - (1 << len) + 1]);
}
int len(int L, int R)
{
    return sums[R] - sums[L - 1];
}
bool solve(int L, int R, bool p)
{
#ifdef debug
    cout << L << ' ' << R << endl;
#endif
    if (L == R)
    {
        return ss[L] == p;
    }
    vector<int> mid;
    mid.push_back(L - 1);
    mid.push_back(query(L, R));
    while (mid.back() < R)
    {
        int nxt = query(mid.back() + 1, R);
        if (s[nxt] == s[mid.back()])
        {
            mid.push_back(nxt);
        }
        else
        {
            break;
        }
    }
    mid.push_back(R + 1);
#ifdef debug
    for (auto i : mid)
    {
        cout << i << ',' << s[i] << ',' << ss[i] << ' ';
    }
    cout << endl;
#endif
    if (len(mid[0] + 1, mid[1] - 1) > s[mid[1]] && solve(mid[0] + 1, mid[1] - 1, p))
    {
        return true;
    }
    for (int i = 1; i + 1 < (int)mid.size(); ++i)
    {
        if (ss[mid[i]] == p)
        {
            if (mid[i - 1] + 1 < mid[i] || mid[i] < mid[i + 1] - 1)
            {
                return true;
            }
        }
        else
        {
            if (len(mid[i] + 1, mid[i + 1] - 1) > s[mid[i]] && solve(mid[i] + 1, mid[i + 1] - 1, p))
            {
                return true;
            }
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> cases;
    for (int i = 2; i <= 1000000; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    while (cases--)
    {
        cin >> S >> T;
        ans = true;
        cnts = cntt = 0;
        for (int i = 0; i < (int)S.length();)
        {
            bool f = S[i] == '+';
            int len = 0;
            while (i < (int)S.length() && ((S[i] == '-') ^ f))
            {
                ++len;
                ++i;
            }
            s[++cnts] = len;
            ss[cnts] = f;
        }
        for (int i = 0; i < (int)T.length();)
        {
            bool f = T[i] == '+';
            int len = 0;
            while (i < (int)T.length() && ((T[i] == '-') ^ f))
            {
                ++len;
                ++i;
            }
            t[++cntt] = len;
            tt[cntt] = f;
        }
        for (int i = 1; i <= cnts; ++i)
        {
            sums[i] = sums[i - 1] + s[i];
#ifdef debug
            cout << s[i] << ' ';
#endif
        }
#ifdef debug
        cout << endl;
        cout << *max_element(s + 1, s + 1 + cnts) << endl;
#endif
        for (int i = 1; i <= cntt; ++i)
        {
            sumt[i] = sumt[i - 1] + t[i];
#ifdef debug
            cout << t[i] << ' ';
#endif
        }
#ifdef debug
        cout << endl;
#endif
        for (int i = 1; i <= cnts; ++i)
        {
            ST[0][i] = i;
        }
#ifdef debug
        cout << "ST" << endl;
#endif
        for (int i = 1; i <= lg[cnts]; ++i)
        {
            for (int j = 1; j <= cnts - (1 << i) + 1; ++j)
            {
                ST[i][j] = MAX(ST[i - 1][j], ST[i - 1][j + (1 << i >> 1)]);
#ifdef debug
                cout << ST[i][j] << ' ';
#endif
            }
#ifdef debug
            cout << endl;
#endif
        }
#ifdef debug
        cout << "END" << endl;
#endif
        int lst = 1, nxt = 0;
        for (int i = 1; i <= cntt; ++i)
        {
            nxt = find(sums + 1, sums + 1 + cnts, sumt[i]) - sums;
            if (nxt > cnts || !solve(lst, nxt, tt[i]))
            {
                ans = false;
                break;
            }
            if (1 < lst && ss[lst] != tt[i])
            {
                ans = false;
                break;
            }
            if (nxt < cnts && ss[nxt] != tt[i])
            {
                ans = false;
                break;
            }
            lst = nxt + 1;
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}