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
#include <atcoder/lazysegtree>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int power(int A, int B)
{
    A %= MOD;
    int res = 1;
    while (B & 1)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
class node
{
private:
    int v, len;

public:
    node()
    {
        v = 1;
        len = 1;
    }
    node(int V, int LEN)
    {
        v = V;
        len = LEN;
    }
    int getv()
    {
        return v;
    }
    int length()
    {
        return len;
    }
};
int n, q, G[200005], a, b, c;
node op(node A, node B)
{
    if (!B.length())
    {
        return A;
    }
    return node((A.getv() * (G[B.length()] - G[B.length() - 1] + MOD) % MOD + B.getv()) % MOD, A.length() + B.length());
}
node e()
{
    return node(0, 0);
}
node mapping(int A, node B)
{
    return A && B.length() ? node(A * G[B.length() - 1] % MOD, B.length()) : B;
}
int composition(int A, int B)
{
    return A ? A : B;
}
int id()
{
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    G[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        G[i] = (G[i - 1] * 10 + 1) % MOD;
    }
    atcoder::lazy_segtree<node, op, e, int, mapping, composition, id> g(n);
    for (int i = 0; i < n; ++i)
    {
        g.set(i, node());
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> c;
        --a;
        g.apply(a, b, c);
        cout << g.all_prod().getv() << endl;
    }
    return 0;
}