#include <bits/stdc++.h>
using namespace std;
namespace FGF
{
	int n, m;
	const int N = 55;
	int a[N][N], rk[N][N], pos[N], nxt[N << 1];
	char s[5];
	vector<int> g[N], t;
	queue<int> q;
	void solve(int op)
	{
		memset(pos, 0, sizeof(pos)), memset(nxt, 0, sizeof(nxt));
		for (int i = 1; i <= n; i++)
		{
			q.push(i);
			g[i].clear();
			for (int j = 1; j <= n; j++)
				g[i].push_back(j);
			sort(g[i].begin(), g[i].end(), [&](int x, int y) { return (a[i][x] < a[i][y]) ^ op; });
		}
		for (int i = 1; i <= n; i++)
		{
			t.clear();
			for (int j = 1; j <= n; j++)
				t.push_back(j);
			sort(t.begin(), t.end(), [&](int x, int y) { return (a[x][i] > a[y][i]) ^ op; });
			for (int j = 0; j < n; j++)
				rk[i][t[j]] = j + 1;
		}
		while (q.size())
		{
			int u = q.front();
			q.pop();
			while (!nxt[u])
			{
				int v = g[u][pos[u]++];
				if (!nxt[v + n] || rk[v][nxt[v + n]] > rk[v][u])
				{
					nxt[nxt[v + n]] = 0;
					if (nxt[v + n])
						q.push(nxt[v + n]);
					nxt[v + n] = u, nxt[u] = v + n;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			std::cout << nxt[i] << std::endl;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				std::cout << a[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void work()
	{
		cin >> m;
		while (m--)
		{
			cin >> n;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					scanf("%d", &a[i][j]);
			cout << "B" << endl;
			cin >> s;
			if (s[0] == 'D')
			{
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						a[i][j] = -a[i][j];
			}
			int x;
			cin >> x;
			solve(x > n);
			cout << nxt[x] << endl;
			cin >> x;
			while (~x)
				cout << nxt[x] << endl, cin >> x;
		}
	}
} // namespace FGF
int main()
{
	FGF::work();
	return 0;
}