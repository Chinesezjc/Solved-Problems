#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
const int mod = 1000000007;

int N, K;
int f[MAXN][105][2][2];
int g[105][2][2];
int size[MAXN];

vector<int> G[MAXN];

inline int Mod(ll x, ll y)
{
	x %= mod, y %= mod;
	return (int)(x + y) % mod;
}

void dp(int u, int fa)
{
	size[u] = 1;
	f[u][0][0][0] = f[u][1][1][0] = 1;
	for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		int v = *it;
		if (v == fa)
			continue;
		dp(v, u);
		for (register int i = 0; i <= min(size[u], K); ++i)
		{
			g[i][0][0] = f[u][i][0][0], f[u][i][0][0] = 0;
			g[i][0][1] = f[u][i][0][1], f[u][i][0][1] = 0;
			g[i][1][0] = f[u][i][1][0], f[u][i][1][0] = 0;
			g[i][1][1] = f[u][i][1][1], f[u][i][1][1] = 0;
		}
		for (register int i = 0; i <= min(size[u], K); ++i)
		{
			for (register int j = 0; j <= min(size[v], K - i); ++j)
			{
				f[u][i + j][0][0] = Mod((ll)f[u][i + j][0][0], (ll)g[i][0][0] * (ll)f[v][j][0][1]);
				f[u][i + j][0][1] = Mod((ll)f[u][i + j][0][1], (ll)g[i][0][0] * (ll)f[v][j][1][1] + (ll)g[i][0][1] * ((ll)f[v][j][1][1] + (ll)f[v][j][0][1]));
				f[u][i + j][1][0] = Mod((ll)f[u][i + j][1][0], (ll)g[i][1][0] * ((ll)f[v][j][0][0] + (ll)f[v][j][0][1]));
				f[u][i + j][1][1] = Mod((ll)f[u][i + j][1][1], (ll)g[i][1][0] * ((ll)f[v][j][1][0] + (ll)f[v][j][1][1]) + (ll)g[i][1][1] * ((ll)f[v][j][0][0] + (ll)f[v][j][0][1] + (ll)f[v][j][1][0] + (ll)f[v][j][1][1]));
			}
		}
		size[u] += size[v];
	}
}

int main()
{
	scanf("%d%d", &N, &K);
	for (register int i = 1; i < N; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp(1, 0);
	printf("%d", (int)(f[1][K][0][1] + f[1][K][1][1]) % mod);
	return 0;
}