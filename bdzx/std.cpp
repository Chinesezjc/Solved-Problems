#include <bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * f;
}
int T, n, p[N];
vector<int> G[N];
ll ans, w[N], b[N];
void dfs(int u, int fa)
{
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		ll t = min(min(min(b[u], b[v]), w[v]), w[u]);
		w[v] -= t, w[u] -= t;
		ans -= t;
	}
}
void Solve()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		G[i].clear();
	for (int i = 1; i < n; ++i)
	{
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		b[i] = read(), p[i] = read();
		ans += b[i];
		w[i] = 1LL * b[i] * p[i];
	}
	dfs(1, 0);
	printf("%lld\n", ans);
}
int main()
{
	T = read();
	while (T--)
	{
		Solve();
	}
	return 0;
}
