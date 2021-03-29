//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define int long long
#define double long double
const int INF = 0x3fffffffffffffff;
const double eps = 0.0000000000001;
const double PI = acos(-1);
const int MOD = 2017;
int n, m, t;
class matrix
{
public:
	int n, m, val[105][105];
	matrix(int N, int M) : n(N), m(M) { memset(val, 0, sizeof(val)); }
	friend matrix operator*(const matrix &A, const matrix &B)
	{
		if (A.m != B.n)
			exit(114514);
		matrix res(A.n, B.m);
		for (int i = 0; i < res.n; ++i)
		{
			for (int j = 0; j < res.m; ++j)
			{
				for (int k = 0; k < A.m; ++k)
				{
					res.val[i][j] = (res.val[i][j] + A.val[i][k] * B.val[k][j]) % MOD;
				}
			}
		}
		return res;
	}
};
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	matrix ans(1, n + 1), z(n + 1, n + 1);
	for (int i = 0; i <= n; ++i)
	{
		z.val[i][i] = 1;
		z.val[i][0] = 1;
	}
	ans.val[0][1] = 1;
	for (int i = 1; i <= m; ++i)
	{
		static int a, b;
		std::cin >> a >> b;
		z.val[a][b] = 1;
		z.val[b][a] = 1;
	}
	std::cin >> t;
	while (t)
	{
		if (t & 1)
		{
			ans = ans * z;
		}
		z = z * z;
		t >>= 1;
	}
	int ANS = 0;
	for (int i = 0; i <= n; ++i)
	{
		ANS = (ANS + ans.val[0][i]) % MOD;
	}
	std::cout << ANS << std::endl;
	return 0;
}