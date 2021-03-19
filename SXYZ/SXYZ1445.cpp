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
const int N = 2;
const int MOD[N] = {1000000007, 1000000009};
const int P = 19260817;
int n, a[200005], ans, LG[30];
struct comp : std::array<int, N>
{
    friend const comp operator+(const comp &A, const comp &B)
    {
        comp res;
        for (int i = 0; i != N; ++i)
            res[i] = (A[i] + B[i]) % MOD[i];
        return res;
    }
    friend const comp operator-(const comp &A, const comp &B)
    {
        comp res;
        for (int i = 0; i != N; ++i)
            res[i] = (A[i] + MOD[i] - B[i]) % MOD[i];
        return res;
    }
    friend const comp operator*(const comp &A, const comp &B)
    {
        comp res;
        for (int i = 0; i != N; ++i)
            res[i] = A[i] * B[i] % MOD[i];
        return res;
    }
    comp &operator+=(const int &val)
    {
        for (int i = 0; i != N; ++i)
            at(i) = (at(i) + val) % MOD[i];
        return *this;
    }
    comp &operator+=(const comp &val)
    {
        for (int i = 0; i != N; ++i)
            at(i) = (at(i) + val[i]) % MOD[i];
        return *this;
    }
    comp &operator*=(const int &val)
    {
        for (int i = 0; i != N; ++i)
            at(i) = at(i) * val % MOD[i];
        return *this;
    }
    int hash() const
    {
        int res = 0;
        for (int i = 0; i != N; ++i)
            res = (res * P + at(i)) % P;
        return res % P;
    }
    friend std::ostream &operator<<(std::ostream &A, const comp &B)
    {
        A << '(' << B[0];
        for (int i = 1; i != N; ++i)
            A << ',' << B[i];
        return A << ')';
    }
} p[200005];
int lg(int now) { return std::upper_bound(LG, LG + 30, now) - LG - 1; }
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % C;
        B >>= 1;
        A = A * A % C;
    }
    return res;
}
struct hash_table
{
    int CNT[1 << 20], cnt, nxt[1 << 20], head[P];
    comp val[1 << 20];
    std::vector<int> x;
    hash_table() { memset(head, -1, sizeof(head)); }
    void clear()
    {
        for (int i = 0; i != x.size(); ++i)
            head[x[i]] = -1;
        x.clear();
        cnt = 0;
    }
    void insert(comp s)
    {
        int hash = s.hash();
        for (int i = head[hash]; ~i; i = nxt[i])
            if (val[i] == s)
                return void(++CNT[i]);
        CNT[cnt] = 1;
        val[cnt] = s;
        nxt[cnt] = head[hash];
        if (!~head[hash])
            x.push_back(hash);
        head[hash] = cnt++;
    }
    int get(comp s)
    {
        int hash = s.hash();
        for (int i = head[hash]; ~i; i = nxt[i])
            if (val[i] == s)
                return CNT[i];
        return 0;
    }
} t;
void work(int L, int R)
{
    if (R - L == 1)
        return void(++ans);
    int mid = (L + R + 1) >> 1, LOG = lg(R - L), max;
    work(L, mid);
    work(mid, R);
    comp left, right, _2;
    t.clear();
    left.fill(0);
    right.fill(0);
    --(max = mid);
    for (int i = mid, j = mid; i-- != L;)
    {
        if (a[i] > a[max])
            max = i;
        left += p[i];
        while (j != R && a[j] < a[max])
            t.insert(right += p[j++]);
        _2 = p[max];
        for (int j = a[max]; j <= a[max] + LOG; ++j, _2 *= 2)
            ans += t.get(_2 - left);
    }
    t.clear();
    left.fill(0);
    right.fill(0);
    max = mid;
    for (int i = mid, j = mid; i != R; ++i)
    {
        if (a[i] > a[max])
            max = i;
        right += p[i];
        while (j != L && a[j - 1] <= a[max])
            t.insert(left += p[--j]);
        _2 = p[max];
        for (int j = a[max]; j <= a[max] + LOG; ++j, _2 *= 2)
            ans += t.get(_2 - right);
    }
}
signed main()
{
    freopen("subseg.in", "r", stdin);
    freopen("subseg.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int i = 0; i != 30; ++i)
        LG[i] = 1 << i;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != N; ++j)
            p[i][j] = power(2, a[i], MOD[j]);
    work(0, n);
    std::cout << ans << std::endl;
    return 0;
}
