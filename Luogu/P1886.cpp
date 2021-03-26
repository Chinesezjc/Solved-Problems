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
int n, m, a[1000005], que[1000005], l, r;
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
	}
	l = 1;
	r = 0;
	for (int i = 1; i < m; ++i)
	{
		while (l <= r && a[que[r]] > a[i])
			--r;
		que[++r] = i;
	}
	for (int i = m; i <= n; ++i)
	{
		while (l <= r && a[que[r]] > a[i])
			--r;
		que[++r] = i;
		if (que[l] == i - m)
			++l;
		std::cout << a[que[l]] << " \n"[i == n];
	}
	l = 1;
	r = 0;
	for (int i = 1; i < m; ++i)
	{
		while (l <= r && a[que[r]] < a[i])
			--r;
		que[++r] = i;
	}
	for (int i = m; i <= n; ++i)
	{
		while (l <= r && a[que[r]] < a[i])
			--r;
		que[++r] = i;
		if (que[l] == i - m)
			++l;
		std::cout << a[que[l]] << " \n"[i == n];
	}
	return 0;
}