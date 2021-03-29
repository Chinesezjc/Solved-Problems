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
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
const int inv2 = (MOD + 1) / 2;
int n, m, a[10][50000], cnt, WAYS = 1, doing, ans;
std::string S;
class node
{
public:
    enum
    {
        num,
        min,
        max,
        unk
    } type;
    int val;
    int dp[1 << 10];
    int lson, rson;
} tree[50005];
int init(int now, int L, int R)
{
    while (S[L] == '(' && S[R - 1] == ')')
    {
        ++L;
        --R;
    }
    if (L + 1 == R && isdigit(S[L]))
    {
        tree[now].type = node::num;
        tree[now].val = S[L] - '0';
        tree[now].lson = -1;
        tree[now].rson = -1;
        return now;
    }
    for (int i = R, tim = 0; i-- != L;)
    {
        switch (S[i])
        {
        case '(':
            --tim;
            break;
        case ')':
            ++tim;
            break;
        case '<':
            if (!tim)
            {
                tree[now].type = node::min;
                tree[now].lson = init(cnt++, L, i);
                tree[now].rson = init(cnt++, i + 1, R);
                return now;
            }
            break;
        case '>':
            if (!tim)
            {
                tree[now].type = node::max;
                tree[now].lson = init(cnt++, L, i);
                tree[now].rson = init(cnt++, i + 1, R);
                return now;
            }
            break;
        case '?':
            if (!tim)
            {
                tree[now].type = node::unk;
                WAYS = (WAYS + WAYS) % MOD;
                tree[now].lson = init(cnt++, L, i);
                tree[now].rson = init(cnt++, i + 1, R);
                return now;
            }
            break;
        }
    }
    throw("NMSL");
}
void visit(int now)
{
    if (~tree[now].lson)
    {
        std::cout << '(';
        visit(tree[now].lson);
        std::cout << ')';
    }
    switch (tree[now].type)
    {
    case node::num:
        std::cout << tree[now].val;
        break;
    case node::max:
        std::cout << '>';
        break;
    case node::min:
        std::cout << '<';
        break;
    case node::unk:
        std::cout << '?';
        break;
    }
    if (~tree[now].rson)
    {
        std::cout << '(';
        visit(tree[now].rson);
        std::cout << ')';
    }
}
int &add(int &A, int B) { return A = (A + B) % MOD; }
void DP(int now)
{
    switch (tree[now].type)
    {
    case node::num:
        for (int i = 1 << tree[now].val; i < 1 << m; i = (i + 1) | 1 << tree[now].val)
            tree[now].dp[i] = 1;
        break;
    case node::max: //and
        DP(tree[now].lson);
        DP(tree[now].rson);
        for (int i = 0; i < 1 << m; ++i)
            tree[now].dp[i] = tree[tree[now].lson].dp[i] * tree[tree[now].rson].dp[i] % MOD;
        break;
    case node::min: //or
        DP(tree[now].lson);
        DP(tree[now].rson);
        for (int i = 0; i < 1 << m; ++i)
            tree[now].dp[i] = (tree[tree[now].lson].dp[i] + tree[tree[now].rson].dp[i] -
                               tree[tree[now].lson].dp[i] * tree[tree[now].rson].dp[i] % MOD + MOD) %
                              MOD;
        break;
    case node::unk:
        DP(tree[now].lson);
        DP(tree[now].rson);
        for (int i = 0; i < 1 << m; ++i)
            tree[now].dp[i] = inv2 * (tree[tree[now].lson].dp[i] + tree[tree[now].rson].dp[i]) % MOD;
        break;
    }
}
std::vector<int> rk;
int CMP;
bool cmp(const int &A, const int &B) { return a[A][CMP] < a[B][CMP]; }
signed main()
{
    // freopen("expr.in", "r", stdin);
    // freopen("expr.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> a[i][j];
        }
    }
    std::cin >> S;
    init(cnt++, 0, S.size());
    // std::cout << clock() << std::endl;
    DP(0);
    std::vector<int> rk;
    for (int i = 0; i < m; ++i)
    {
        rk.push_back(i);
    }
    // for (int i = 0; i < cnt; ++i)
    // {
    //     for (int j = 0; j < 1 << m; ++j)
    //         std::cout << tree[i].dp[j] << ' ';
    //     std::cout << std::endl;
    // }
    for (int i = 0; i < n; ++i)
    {
        CMP = i;
        std::sort(rk.begin(), rk.end(), cmp);
        for (int j = 0, s = 0, lst = 0; j < m; ++j, lst = tree[0].dp[s])
        {
            s |= 1 << rk[j];
            ans = (ans + a[rk[j]][i] * (tree[0].dp[s] - lst + MOD) % MOD) % MOD;
        }
    }
    // std::cout << clock() << std::endl;
    std::cout << ans * WAYS % MOD << std::endl;
    return 0;
}