// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = INT_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, a[3005], s[3005], dp[3005], cnt[3005];
int check(int slope)
{
	dp[0] = cnt[0] = 0;
	std::fill(dp + 1, dp + 1 + n, INF);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
			if (dp[i] > s[i] * s[i] - 2 * s[j] * s[i] + s[j] * s[j] + dp[j] + slope)
				dp[i] = s[i] * s[i] - 2 * s[j] * s[i] + s[j] * s[j] + dp[j] + slope, cnt[i] = cnt[j] + 1;
	return cnt[n];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i], s[i] = s[i - 1] + a[i];
	int l = 0, r = INF;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid) > m)
			l = mid + 1;
		else
			r = mid;
	}
	check(l);
	for (int i = 1; i <= n; ++i)
		std::cout << dp[i] << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << cnt[i] << std::endl;
	std::cout << l << std::endl;
	std::cout << (dp[n] - l * m) * m - s[n] * s[n] << std::endl;
	return 0;
}