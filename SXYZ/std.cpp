#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500000;

int n, a[N * 2 + 9];

void into()
{
	scanf("%d", &n);
	for (int i = 1; i < n << 1; ++i)
		scanf("%d", &a[i]);
}

struct list_node
{
	int last, next;
} d[N * 2 + 9];

void Erase(int x, int y)
{
	d[x].next = d[y].next;
	d[d[y].next].last = x;
}

int pos[N + 9], nxt[N * 2 + 9];
stack<int> sta;

void Divide_ans(int l, int r, int rot)
{
	if (l > r)
		return;
	if (r - l & 1)
	{
		puts("no");
		exit(0);
	}
	for (int i = l; i <= r; i = d[i].next)
	{
		if (!a[i])
			continue;
		for (; nxt[i];)
		{
			int p = nxt[i];
			if (p > r)
			{
				puts("no");
				exit(0);
			}
			Divide_ans(d[i].next, d[p].last, a[i]);
			Erase(i, p);
			nxt[i] = nxt[p];
		}
	}
	int c = 0, c0 = 0;
	for (int i = l; i <= r; i = d[i].next)
		c += (bool)a[i], c0 += !a[i];
	if (c0 < c - 1)
	{
		puts("no");
		exit(0);
	}
	for (int i = l; i <= r && c0 > c; i = d[i].next)
		if (!a[i])
		{
			if (sta.empty())
			{
				puts("no");
				exit(0);
			}
			a[i] = sta.top();
			sta.pop();
			++c;
			--c0;
		}
	for (int i = l; d[i].next <= r;)
	{
		if (!a[i] || d[i].last < l || d[i].next > r)
		{
			i = d[i].next;
			continue;
		}
		int x = d[i].last, y = d[i].next;
		if (!a[x] && a[y] || a[x] && !a[y])
		{
			a[x] = a[y] = a[x] | a[y];
			Erase(x, y);
			i = d[x].last;
		}
		else
			i = d[i].next;
	}
	for (int i = l; i <= r; i = d[i].next)
		if (!a[i])
			a[i] = rot;
}

void Get_ans()
{
	if (a[1] && a[n * 2 - 1] && a[1] ^ a[n * 2 - 1])
	{
		puts("no");
		exit(0);
	}
	a[1] = a[n * 2 - 1] = a[1] | a[n * 2 - 1];
	for (int i = 1; i < n << 1; ++i)
		d[i].last = i - 1, d[i].next = i + 1;
	d[0].next = 1;
	for (int i = n * 2 - 1; i >= 1; --i)
	{
		if (!a[i])
			continue;
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
		if (!pos[i])
			sta.push(i);
	Divide_ans(1, n * 2 - 1, 0);
	for (int i = 1; i < n << 1; ++i)
		pos[a[i]] = 1;
	for (int i = 1; i <= n; ++i)
		if (!pos[i])
		{
			puts("no");
			exit(0);
		}
}

void work()
{
	Get_ans();
}

void outo()
{
	puts("yes");
	for (int i = 1; i < n << 1; ++i)
		printf("%d ", a[i]);
	puts("");
}

int main()
{
	into();
	work();
	outo();
	return 0;
}