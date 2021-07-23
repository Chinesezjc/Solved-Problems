// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 23333;
int n, m;
std::vector<int> operator*(const std::vector<int> &A, const std::vector<int> &B)
{
	std::vector<int> res(n + 1);
	for (int i = 0; i != (int)A.size(); ++i)
		for (int j = 0; j != (int)B.size(); ++j)
			if (i + j <= n)
				res[i + j] = (res[i + j] + A[i] * B[j]) % MOD;
	return res;
}
std::vector<int> operator+(const std::vector<int> &A, const std::vector<int> &B)
{
	std::vector<int> res(n + 1);
	for (int i = 0; i != (int)A.size(); ++i)
		res[i] = (res[i] + A[i]) % MOD;
	for (int i = 0; i != (int)B.size(); ++i)
		res[i] = (res[i] + B[i]) % MOD;
	return res;
}
std::vector<int> F;
void print(const std::vector<int> &x)
{
	for (auto i : x)
		std::cout << ' ' << i;
	std::cout << std::endl;
}
std::vector<int> power(std::vector<int> A, int B)
{
	std::vector<int> res({1});
	while (B)
	{
		if (B & 1)
			res = res * A;
		A = A * A;
		B >>= 1;
	}
	return res;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	freopen("dishash.in", "r", stdin);
	freopen("dishash.out", "w", stdout);
	std::cin >> n >> m;
	F = {1};
	for (int i = 0; i != 300; ++i)
		F = power(F, m) * std::vector<int>({0, 1}) + std::vector<int>({1});
	// print(F);
	std::cout << (F[n] + 1) % MOD << std::endl;
	return 0;
}