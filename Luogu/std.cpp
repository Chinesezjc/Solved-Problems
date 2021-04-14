#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FIR first
#define SEC second
#define ll long long
#define ull unsigned long long
using namespace std;
template <class T>
inline void rd(T &x)
{
    x = 0;
    char c = getchar();
    int f = 1;

    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;

        c = getchar();
    }

    while (isdigit(c))
        x = x * 10 - '0' + c, c = getchar();

    x *= f;
}
const int N = 1e5 + 10;
const int mod = 998244353;
inline ll Pow(ll x, int y)
{
    int res = 1;

    for (; y; y >>= 1, x = x * (ll)x % mod)
        if (y & 1)
            res = res * (ll)x % mod;

    return res;
}
inline ll Sqr(ll x)
{
    return x * x % mod;
}
struct quer
{
    int id, y;
};
vector<quer> Q[N];
int qans[N];

struct Num
{
    ll x, y;
    Num(ll x = 0, ll y = 0) : x(x), y(y) {}
    friend Num operator+(Num A, Num B)
    {
        return Num(A.x + B.x, A.y + B.y);
    }
    friend bool operator<(Num A, Num B)
    {
        return (ull)A.x * B.y < (ull)A.y * B.x;
    }
    friend bool operator>(Num A, Num B)
    {
        return (ull)A.x * B.y > (ull)A.y * B.x;
    }
    ll cal()
    {
        return (y % mod) * Sqr((x % mod) * Pow(y % mod, mod - 2) % mod) % mod;
    }
};
ll sum[N], sum2[N], x[N];
int n;
int A[N], B[N], pA, pB;
Num vA[N], vB[N];
ll sA[N], sB[N];

int ql, qr;
void getL(int delta, int R)
{
    int lb = 0, rb = pA;

    while (lb < rb)
    {
        int mid = lb + rb + 1 >> 1;

        if (Num(sum[R - 1] - sum[A[mid]] + delta, R - 1 - A[mid]) > vA[mid])
            lb = mid;
        else
            rb = mid - 1;
    }

    ql = lb;
}
void getR(int delta)
{
    int lb = 0, rb = pB;

    while (lb < rb)
    {
        int mid = lb + rb + 1 >> 1;
        getL(delta, B[mid]);

        //      cout<<"QL:"<<B[mid]<<' '<<A[ql]<<' '<<sum[B[mid]-1]-sum[A[ql]]+delta<<' '<<B[mid]-1-A[ql]<<endl;
        if (Num(sum[B[mid] - 1] - sum[A[ql]] + delta, B[mid] - 1 - A[ql]) < vB[mid])
            lb = mid;
        else
            rb = mid - 1;
    }

    getL(delta, B[lb]);
    qr = lb;
}

int solve(int delta)
{
    getR(delta);
    //  cout<<A[ql]<<' '<<B[qr]<<endl;
    return (sA[ql] + sB[qr] + (Num(sum[B[qr] - 1] - sum[A[ql]] + delta, B[qr] - 1 - A[ql])).cal()) % mod;
}

vector<int> del[N];
int main()
{
    int q;
    rd(n), rd(q);

    for (int i = 1; i <= n; ++i)
        rd(x[i]), sum[i] = sum[i - 1] + x[i], sum2[i] = (sum2[i - 1] + Sqr(x[i])) % mod;

    for (int i = 1, a, b; i <= q; ++i)
    {
        rd(a), rd(b);
        Q[a].PB((quer){
            i, b - (int)x[a]});
    }

    B[0] = n + 1;

    for (int i = n; i >= 1; --i)
    {
        Num tmp = Num(x[i], 1);

        while (pB && vB[pB] < tmp)
        {
            del[i].PB(B[pB]);
            tmp = tmp + vB[pB], pB--;
        }

        B[++pB] = i, sB[pB] = (sB[pB - 1] + (vB[pB] = tmp).cal()) % mod;
    }

    printf("%lld\n", ((sum2[n] - sB[pB]) % mod + mod) % mod);

    for (int i = 1; i <= n; ++i)
    {
        --pB;

        for (int j = (int)del[i].size() - 1; j >= 0; --j)
        {
            B[++pB] = del[i][j];
            sB[pB] = (sB[pB - 1] + (vB[pB] = Num(sum[B[pB - 1] - 1] - sum[B[pB] - 1], B[pB - 1] - B[pB])).cal()) % mod;
        }

        //      cout<<"solving:"<<i<<endl;
        //      for(int i=1;i<=pA;++i) printf("(%d, %lld,%lld)",A[i],vA[i].x,vA[i].y); cout<<endl;
        //      for(int i=1;i<=pB;++i) printf("(%d, %lld,%lld)",B[i],vB[i].x,vB[i].y); cout<<endl;

        ll tsum = (sum2[n] - Sqr(x[i])) % mod;

        for (int j = 0; j < Q[i].size(); ++j)
            qans[Q[i][j].id] = (tsum + Sqr(x[i] + Q[i][j].y) - solve(Q[i][j].y)) % mod;

        Num tmp = Num(x[i], 1);

        while (pA && vA[pA] > tmp)
            tmp = tmp + vA[pA], pA--;

        A[++pA] = i, sA[pA] = (sA[pA - 1] + (vA[pA] = tmp).cal()) % mod;
    }

    for (int i = 1; i <= q; ++i)
        printf("%lld\n", (qans[i] + mod) % mod);

    return 0;
}