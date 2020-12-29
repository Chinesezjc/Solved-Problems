/*
 * Author : _Wallace_
 * Source : https://www.cnblogs.com/-Wallace-/
 * Problem : SPOJ REPEATS Repeats
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;
const int N = 5e4 + 5;
const int S = 2;
const int inf = 1e9;
int n;

namespace SAM
{
    const int T = N << 1;

    struct Node
    {
        int ch[S];
        int link, len;
    } t[T];

    set<int> ep[T];
    int rt[T], siz[T], mn[T];

    int total;
    int last;

    inline void reset()
    {
        memset(t, 0, sizeof(t));
        total = last = 1;

        rt[1] = 1, mn[1] = inf, siz[1] = 0;
    }

    inline void extend(int c)
    {
        int p = last, np = last = ++total;
        t[np].len = t[p].len + 1;

        ep[np].insert(t[np].len);
        siz[np] = 1, mn[np] = inf, rt[np] = np;

        for (; p && !t[p].ch[c]; p = t[p].link)
            t[p].ch[c] = np;

        if (!p)
        {
            t[np].link = 1;
        }
        else
        {
            int q = t[p].ch[c];
            if (t[p].len + 1 == t[q].len)
            {
                t[np].link = q;
            }
            else
            {
                int nq = ++total;
                t[nq] = t[q], t[nq].len = t[p].len + 1;
                t[np].link = t[q].link = nq;

                mn[nq] = inf, rt[nq] = nq, siz[nq] = 0;

                for (; p && t[p].ch[c] == q; p = t[p].link)
                    t[p].ch[c] = nq;
            }
        }
    }

    int b[N << 1], c[N];
    void topo_sort()
    {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= total; i++)
            ++c[t[i].len];
        for (int i = 1; i <= n; i++)
            c[i] += c[i - 1];
        for (int i = 1; i <= total; i++)
            b[c[t[i].len]--] = i;
    }

    void join(int x, int y)
    {
        if (siz[rt[x]] < siz[rt[y]])
            swap(rt[x], rt[y]);
        x = rt[x], y = rt[y];
        for (set<int>::iterator i = ep[y].begin(), j; i != ep[y].end(); i++)
        {
            j = ep[x].insert(*i).first;
            if (j != ep[x].begin())
                mn[x] = min(mn[x], *i - *(--j)), ++j;
            if (++j != ep[x].end())
                mn[x] = min(mn[x], *j - *i);
            ++siz[x];
        }
        ep[y].clear();
    }

    int calc()
    {
        topo_sort();
        int ans = 0;
        for (int i = total; i > 1; i--)
        {
            int x = b[i], g = mn[rt[x]];
            ans = max(ans, (t[x].len + g) / g);
            join(t[x].link, x);
        }
        ep[rt[1]].clear();
        return ans;
    }
} // namespace SAM

void solve()
{
    SAM::reset();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        SAM::extend(c - 'a');
    }
    cout << SAM::calc() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}