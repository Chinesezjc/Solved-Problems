#include <iostream>
#include <cstring>
#include <cstdio>
#define MX 20001
#define S 0
#define T ((n << 1) + 1)
#define oo 12312312
using namespace std;
typedef struct edge_t
{
	int u, v, c;
} edge;
edge e[MX];
int fst[MX], nxt[MX], lnum;
int n, m;
void addeg(int nu, int nv, int nc)
{
	nxt[++lnum] = fst[nu];
	fst[nu] = lnum;
	e[lnum] = (edge){nu, nv, nc};
}
void input()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		addeg(a, n + b, 1);
		addeg(n + b, a, 0);
	}
	for (int i = 1; i <= n; i++)
		addeg(S, i, 1), addeg(i, S, 0);
	for (int i = n + 1; i <= n << 1; i++)
		addeg(i, T, 1), addeg(T, i, 0);
}
void init()
{
	memset(fst, 0xff, sizeof(fst));
	lnum = -1;
}
int dep[MX], q[MX];
int bfs(int frm, int to)
{
	int x, y, h = 0, t = 1;
	memset(dep, 0xff, sizeof(dep));
	q[++h] = frm;
	dep[frm] = 0;
	while (h >= t)
	{
		x = q[t++];
		for (int i = fst[x]; i != -1; i = nxt[i])
		{
			y = e[i].v;
			if (e[i].c && dep[y] == -1)
			{
				dep[y] = dep[x] + 1;
				q[++h] = y;
			}
		}
	}
	return (dep[to] >= 0);
}
int dinic(int to, int x, int mn)
{
	if (x == to)
		return mn;
	int a, now = 0, y;
	for (int i = fst[x]; i != -1; i = nxt[i])
	{
		y = e[i].v;
		if (e[i].c && dep[y] == dep[x] + 1)
		{
			a = dinic(to, y, min(mn - now, e[i].c));
			now += a;
			e[i].c -= a;
			e[i ^ 1].c += a;
			if (now == mn)
				break;
		}
	}
	return now;
}
void output(int x)
{
	printf("%d ", x);
	for (int i = fst[x]; i != -1; i = nxt[i])
		if (e[i].c == 0 && e[i].v > n)
			output(e[i].v - n);
}
int fa[MX];
int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }
void work()
{
	int tot = 0;
	while (bfs(S, T))
		tot += dinic(T, S, +oo);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 0; i <= lnum; i++)
		if (e[i].u >= 1 && e[i].u <= n && e[i].v > n && e[i].v < T && e[i].c == 0)
			fa[findfa(e[i].v - n)] = findfa(e[i].u);
	for (int i = 1; i <= n; i++)
		if (findfa(i) == i)
			output(i), putchar('\n');
	printf("%d\n", n - tot);
}
int main()
{
	init();
	input();
	work();
	return 0;
}