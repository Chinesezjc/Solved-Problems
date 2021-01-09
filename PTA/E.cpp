//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, has[10], used[10];
string a, b, ans;
bool great(const char &A, const char &B)
{
    return A > B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        if (b.length() > a.length())
        {
            sort(a.begin(), a.end(), great);
            cout << a << endl;
            continue;
        }
        if (b.length() < a.length())
        {
            cout << -1 << endl;
            continue;
        }
        memset(has, 0, sizeof(has));
        for (int i = 0; i < a.length(); ++i)
        {
            ++has[a[i] ^ '0'];
        }
        ans = string(b.length(), '0');
        for (int i = 0; i <= b.length(); ++i)
        {
            a = "";
            memset(used, 0, sizeof(used));
            for (int j = 0; j < i; ++j)
            {
                if (used[b[j] ^ '0'] < has[b[j] ^ '0'])
                {
                    ++used[b[j] ^ '0'];
                    a += b[j];
                }
                else
                {
                    break;
                }
            }
            if (a.length() < i)
            {
                continue;
            }
            if (a.length() == b.length())
            {
                ans = max(ans, a);
                continue;
            }
            for (int j = (b[i] ^ '0') - 1; j; --j)
            {
                if (used[j] < has[j])
                {
                    a += '0' | j;
                    ++used[j];
                    break;
                }
            }
            for (int j = i + 1; j < b.length(); ++j)
            {
                for (int k = 9; k; --k)
                {
                    if (used[k] < has[k])
                    {
                        a += '0' | k;
                        ++used[k];
                        break;
                    }
                }
            }
            if (a > b || a.length() != b.length())
            {
                continue;
            }
            ans = max(ans, a);
        }
        cout << (ans.front() == '0' ? "-1" : ans) << endl;
    }
    return 0;
}