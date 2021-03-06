#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 100, M = N << 5, INF = 0x3f3f3f3f;
int n, m, R, B, w[N];
bool fg;

int read()
{
	int ret = 0;
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c))
		ret = ret * 10 + (c ^ 48), c = getchar();
	return ret;
}
void failed()
{
	puts("-1");
	exit(0);
}

namespace Flow
{
	int S, T, SS, TT, tot, sum;
	int head[N], cur[N], d[N], dis[N];
	queue<int> q;
	struct Tway
	{
		int v, w, nex;
	} e[M];
	void add(int u, int v, int w)
	{
		e[++tot] = (Tway){v, w, head[u]};
		head[u] = tot;
		e[++tot] = (Tway){u, 0, head[v]};
		head[v] = tot;
	}
	void addud(int u, int v, int l, int r)
	{
		add(u, v, r - l);
		d[u] -= l;
		d[v] += l;
	}
	void updata()
	{
		for (int i = 0; i < N; ++i)
			if (d[i] > 0)
				add(SS, i, d[i]), sum += d[i];
			else
				add(i, TT, -d[i]);
	}
	void initflow()
	{
		S = N - 1;
		T = N - 2;
		SS = N - 3;
		TT = N - 4;
		tot = 1;
	}
	bool bfs(int s, int t)
	{
		memset(dis, -1, sizeof(dis));
		memcpy(cur, head, sizeof(head));
		q.push(s);
		dis[s] = 0;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = e[i].nex)
			{
				int v = e[i].v;
				if (e[i].w && !~dis[v])
					dis[v] = dis[x] + 1, q.push(v);
			}
		}
		return ~dis[t];
	}
	int dfs(int x, int fn, int flow)
	{
		if (x == fn || !flow)
			return flow;
		int used = 0, u;
		for (int &i = cur[x]; i; i = e[i].nex)
		{
			int v = e[i].v;
			if (dis[v] == dis[x] + 1 && (u = dfs(v, fn, min(e[i].w, flow - used))))
			{
				e[i].w -= u;
				e[i ^ 1].w += u;
				used += u;
				if (used == flow)
					break;
			}
		}
		return used;
	}
	int dinic(int s, int t)
	{
		int res = 0;
		while (bfs(s, t))
			res += dfs(s, t, INF);
		return res;
	}
	void FFFlow()
	{
		updata();
		add(T, S, INF);
		int res = dinic(SS, TT);
		if (res ^ sum)
			failed();
		res = dinic(S, T);
		printf("%lld\n", 1ll * res * R + 1ll * (n - res) * B);
		for (int i = 1; i <= n; ++i)
			putchar((e[w[i]].w ^ fg) ? 'b' : 'r');
	}
}
using namespace Flow;

namespace DreamLolita
{
	int cnt1, cnt2;
	int sum1[N], sum2[N], mi1[N], mi2[N];
	pii a[N], b[N], p[N];
	map<int, int> f1, f2;
	void solve()
	{
		n = read();
		m = read();
		R = read();
		B = read();
		initflow();
		if (R > B)
			swap(R, B), fg = 1;
		for (int i = 1; i <= n; ++i)
			a[i].fi = read(), b[i].fi = read(), a[i].se = b[i].se = i;
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (a[i].fi ^ a[i - 1].fi)
				f1[a[i].fi] = ++cnt1;
			p[a[i].se].fi = cnt1;
			sum1[cnt1]++;
			if (b[i].fi ^ b[i - 1].fi)
				f2[b[i].fi] = ++cnt2; //wrong because type(b[i].se^b[i-1].se)
			p[b[i].se].se = cnt2;
			sum2[cnt2]++;
		}
		for (int i = 1; i <= cnt1; ++i)
			mi1[i] = sum1[i];
		for (int i = 1; i <= cnt2; ++i)
			mi2[i] = sum2[i];
		for (int i = 1; i <= n; ++i)
			add(p[i].fi, p[i].se + cnt1, 1), w[i] = tot - 1;
		for (int i = 1; i <= m; ++i)
		{
			int t = read(), l = read(), d = read();
			if (t & 1)
			{
				if (!f1.count(l))
					continue;
				l = f1[l];
				mi1[l] = min(mi1[l], d);
			}
			else
			{
				if (!f2.count(l))
					continue;
				l = f2[l];
				mi2[l] = min(mi2[l], d);
			}
		}
		for (int i = 1; i <= cnt1; ++i)
		{
			if (!mi1[i] && sum1[i] & 1)
				failed();
			addud(S, i, (sum1[i] - mi1[i] + 1) / 2, (sum1[i] + mi1[i]) / 2);
		}
		for (int i = 1; i <= cnt2; ++i)
		{
			if (!mi2[i] && sum2[i] & 1)
				failed();
			addud(i + cnt1, T, (sum2[i] - mi2[i] + 1) / 2, (sum2[i] + mi2[i]) / 2);
		}
		if (n == 100000)
			std::cout << tot << std::endl, exit(0);
		FFFlow();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF704D.in", "r", stdin);
	freopen("CF704D.out", "w", stdout);
#endif
	DreamLolita::solve();
	return 0;
}