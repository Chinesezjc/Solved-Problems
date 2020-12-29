//This code was made by Chinese_zjc_.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int Max(const int &A, const int &B)
{
	return A < B ? B : A;
}
int dp[4000101], ti, t, n, m, cnt[4000101], sum[4000101], from[4000101], ans = INF;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ti;
		++cnt[ti];
		sum[ti] += ti;
		t = max(ti, t);
	}
	for (int i = 1; i < t + m; ++i)
	{
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < t + m; ++i)
	{
		// if (i >= m && cnt[i] == cnt[i - m])
		// {
		// 	dp[i] = dp[i - m];
		// 	continue;
		// }
		dp[i] = i * cnt[i] - sum[i];
		for (int j = Max(0, i - m - m + 1); j <= i - m; ++j)
		{
			if (dp[i] <= dp[j] + i * (cnt[i] - cnt[j]) - sum[i] + sum[j])
			{
				from[i] = j;
			}
			dp[i] = min(dp[i], dp[j] + i * (cnt[i] - cnt[j]) - sum[i] + sum[j]);
		}
	}
	for (int i = t; i < t + m; ++i)
	{
		ans = min(dp[i], ans);
	}
	cout << ans;
	return 0;
}
