#include <bits/stdc++.h>
namespace my_std
{
	using namespace std;
#define pll pair<ll, ll>
#define fir first
#define sec second
#define MP make_pair
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define drep(i, x, y) for (int i = (x); i >= (y); i--)
#define go(x) for (int i = head[x]; i; i = edge[i].nxt)
#define templ template <typename T>
#define sz 333333
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
	templ inline bool chkmax(T &x, T y) { return x < y ? x = y, 1 : 0; }
	templ inline bool chkmin(T &x, T y) { return x > y ? x = y, 1 : 0; }
	templ inline void read(T &t)
	{
		t = 0;
		char f = 0, ch = getchar();
		double d = 0.1;
		while (ch > '9' || ch < '0')
			f |= (ch == '-'), ch = getchar();
		while (ch <= '9' && ch >= '0')
			t = t * 10 + ch - 48, ch = getchar();
		if (ch == '.')
		{
			ch = getchar();
			while (ch <= '9' && ch >= '0')
				t += d * (ch ^ 48), d *= 0.1, ch = getchar();
		}
		t = (f ? -t : t);
	}
	template <typename T, typename... Args>
	inline void read(T &t, Args &...args)
	{
		read(t);
		read(args...);
	}
	char __sr[1 << 21], __z[20];
	int __C = -1, __zz = 0;
	inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
	inline void print(int x)
	{
		if (__C > 1 << 20)
			Ot();
		if (x < 0)
			__sr[++__C] = '-', x = -x;
		while (__z[++__zz] = x % 10 + 48, x /= 10)
			;
		while (__sr[++__C] = __z[__zz], --__zz)
			;
		__sr[++__C] = '\n';
	}
	void file()
	{
#ifdef NTFOrz
		freopen("a.in", "r", stdin);
#endif
	}
	inline void chktime()
	{
#ifdef NTFOrz
		cerr << clock() / 1000.0 << '\n';
#endif
	}
#ifdef mod
	ll ksm(ll x, int y)
	{
		ll ret = 1;
		for (; y; y >>= 1, x = x * x % mod)
			if (y & 1)
				ret = ret * x % mod;
		return ret;
	}
	ll inv(ll x) { return ksm(x, mod - 2); }
#else
	ll ksm(ll x, int y)
	{
		ll ret = 1;
		for (; y; y >>= 1, x = x * x)
			if (y & 1)
				ret = ret * x;
		return ret;
	}
#endif
	//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;
#define ALL(a) a.begin(), a.end()

ll F[sz * 10], W[sz * 10], sum[sz * 10], Fsum[sz * 10];
int C;
namespace FLOW
{
	struct hh
	{
		int t;
		ll w, c;
		int nxt;
	} edge[sz << 1];
	int head[sz], ecnt = 1;
	void make_edge(int f, int t, ll w, ll c)
	{
		//		printf("%d %d %lld %lld\n",f,t,w,c);
		edge[++ecnt] = (hh){t, w, c, head[f]};
		head[f] = ecnt;
		edge[++ecnt] = (hh){f, 0, -c, head[t]};
		head[t] = ecnt;
	}
	int S, T;
	ll fl[sz];
	int pre[sz], in[sz];
	ll dis[sz];
	void SPFA()
	{
		rep(i, 1, T) dis[i] = -1e18, fl[i] = 0, in[i] = 0, pre[i] = 0;
		fl[S] = 1e18;
		dis[S] = 0;
		queue<int> q;
		q.push(S);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			in[x] = 0;
#define v edge[i].t
			go(x) if (edge[i].w && chkmax(dis[v], dis[x] + edge[i].c))
			{
				pre[v] = i, fl[v] = min(fl[x], edge[i].w);
				if (!in[v])
					q.push(v), in[v] = 1;
			}
#undef v
		}
	}
	void work()
	{
		while (233)
		{
			SPFA();
			F[++C] = fl[T], W[C] = dis[T];
			if (fl[T] < 1e15)
				sum[C] = sum[C - 1] + F[C] * W[C], Fsum[C] = Fsum[C - 1] + F[C];
			else
				break;
			for (int x = T; x != S; x = edge[pre[x] ^ 1].t)
				edge[pre[x]].w -= fl[T], edge[pre[x] ^ 1].w += fl[T];
		}
	}
}
using FLOW::make_edge;

int n, m;
int K[sz];
vector<pair<pll, ll>> S[sz];
//int U[sz],V[sz],_K[sz][sz];

int main()
{
	file();
	read(n);
	rep(i, 1, n)
	{
		read(K[i]);
		S[i].push_back(MP(MP(0, 0), 0));
		ll x, y, z;
		rep(j, 1, K[i]) read(x, y, z), S[i].push_back(MP(MP(x, y), z));
		sort(ALL(S[i]));
	}
	read(m);
	int _S = FLOW::S = (n + 1) * 35 + 1, _T = FLOW::T = FLOW::S + 1;
	rep(i, 1, m)
	{
		//		read(U[i],V[i]); ll w; read(w);
		int u, v;
		ll w;
		read(u, v, w);
		rep(j, 1, K[u])
		{
			int k = lower_bound(ALL(S[v]), MP(MP(S[u][j].fir.fir + w + 1, 0ll), 0ll)) - S[v].begin() - 1;
			make_edge(v * 35 + k, u * 35 + j, 1e18, 0);
		}
	}
	rep(i, 1, n) make_edge(i * 35 + K[i], _T, 1e18, 0), make_edge(_S, i * 35, 1e18, 0);
	rep(i, 1, n) rep(j, 1, K[i]) make_edge(i * 35 + j - 1, i * 35 + j, 1e18, -S[i][j].sec), make_edge(i * 35 + j, i * 35 + j - 1, 1e18, 0);
	rep(i, 1, n) rep(j, 1, K[i]) make_edge(i * 35 + j - 1, i * 35 + j, S[i][j].fir.sec, 0);
	//	{ ll p=S[i][j].fir.sec-(j==K[i]?0:S[i][j+1].fir.sec); if (p>0) make_edge(_S,i*35+j,p,0); }
	FLOW::work();
	int Q;
	for (int i = 1; i <= C; ++i)
		std::cout << W[i] << ' ' << Fsum[i] << std::endl;
	read(Q);
	while (Q--)
	{
		ll a;
		read(a);
		std::cout << W[C] << std::endl;
		if (a + W[C] > 0)
		{
			puts("-1");
			continue;
		}
		int k = lower_bound(W + 1, W + C + 1, -a, [](ll x, ll y) { return x > y; }) - W - 1;
		printf("%lld\n", sum[k] + Fsum[k] * a);
	}
	return 0;
}