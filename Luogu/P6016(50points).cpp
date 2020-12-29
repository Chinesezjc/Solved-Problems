//This code was made by Chinese_zjc_.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 998244353
using namespace std;
int n, t, x, y, a[501], b[501][501], ans, P[501], z, anss[11];
void read(int &X)
{
	X = 0;
	char c = getchar();
	while ('0' > c || c > '9')
	{
		c = getchar();
	}
	while ('0' <= c && c <= '9')
	{
		X = (X << 3) + (X << 1) + (c ^ '0');
		c = getchar();
	}
}
struct s
{
	bool p[501];
	s()
	{
		clear();
	}
	void clear()
	{
		fill(p + 1, p + 1 + n, false);
	}
} p[2][501];
s S(s A, s B)
{
	s tmp;
	for (int i = 1; i <= n; ++i)
	{
		tmp.p[i] = A.p[i] || B.p[i];
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	read(n);
	read(t);
	for (int i = 1; i <= n; ++i)
	{
		read(P[i]);
		read(x);
		p[0][i].p[i] = true;
		while (x)
		{
			--x;
			read(y);
			b[y][++a[y]] = i;
		}
	}
	for (int i = 1; i <= t; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			p[i & 1][j].clear();
		}
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= a[j]; ++k)
			{
				p[i & 1][b[j][k]] = S(p[i & 1][b[j][k]], p[!(i & 1)][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		z = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (p[t & 1][i].p[j])
			{
				z = z + P[j] - z * P[j];
				z %= MOD;
				if (z < 0)
				{
					z += MOD;
				}
			}
		}
		ans += z;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
