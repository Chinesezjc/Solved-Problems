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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n, m, a[1000005], x, y, kill[1000005], ans, big[1000005], small[1000005];
bool killed[1000005];
struct L
{
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v == __Val.v ? p < __Val.p : v < __Val.v;
    }
    friend ostream &operator<<(ostream &ost, const L &__Val)
    {
        return ost << "(" << __Val.v << ',' << __Val.p << ")";
    }
};
list<L> que;
// void print(list<L> &nmsl)
// {
//     for (auto i : nmsl)
//     {
//         cout << i;
//     }
//     cout << endl;
// }
template <typename T>
void read(T &x)
{
    x = 0;
    char c = getchar();
    while ('0' > c || c > '9')
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x = x * 10 + (c & 15);
        c = getchar();
    }
}
signed main()
{
    // cin >> T;
    read(T);
    for (int C = 1; C <= T; ++C)
    {
        if (C == 1)
        {
            // cin >> n;
            read(n);
            for (int i = 1; i <= n; ++i)
            {
                // cin >> a[i];
                read(a[i]);
            }
        }
        else
        {
            // cin >> m;
            read(m);
            for (int i = 1; i <= m; ++i)
            {
                // cin >> x >> y;
                read(x);
                read(y);
                a[x] = y;
            }
        }
        que.clear();
        for (int i = 1; i <= n; ++i)
        {
            que.push_back({a[i], i});
        }
        // print(que);
        list<L>::iterator jb = que.end();
        for (int i = 1; i < n; ++i)
        {
            list<L>::iterator A = --que.end(), B = que.begin();
            L nxt = L{A->v - B->v, A->p};
            big[i] = A->p;
            small[i] = B->p;
            if (A == jb)
            {
                ++jb;
            }
            if (B == jb)
            {
                ++jb;
            }
            que.erase(A);
            que.erase(B);
            while (jb != que.begin() && !(*--jb < nxt))
                ;
            if (*jb < nxt)
            {
                que.insert(++jb, nxt);
            }
            else
            {
                que.insert(jb, nxt);
            }
            // print(que);
        }
        memset(killed, false, sizeof(killed));
        ans = n - 1;
        for (int i = n - 1; i; --i)
        {
            if (killed[big[i]])
            {
                for (int j = ans; j > i; --j)
                {
                    killed[small[j]] = false;
                }
                ans = i - 1;
                continue;
            }
            killed[small[i]] = true;
        }
        cout << n - ans << endl;
    }
    return 0;
}