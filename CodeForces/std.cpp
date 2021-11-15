// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
std::vector<int> A = {22, 61, 86, 127, 140, 151},
				 B = {35, 47, 94, 121, 146, 148};
int power(int A, int B)
{
	int res = 1;
	while (B)
	{
		if (B & 1)
			res = 1ll * res * A % MOD;
		A = 1ll * A * A % MOD;
		B >>= 1;
	}
	return res;
}
void add(int &A, int B) { A = (A + B) % MOD; }
void mul(int &A, int B) { A = 1ll * A * B % MOD; }
signed main()
{
	std::ios::sync_with_stdio(false);
	for (int i = 0; i <= 24; ++i)
	{
		int AA = 1, BB = 1;
		for (auto j : A)
			mul(AA, j);
		for (auto j : B)
			mul(BB, j);
		std::cout << AA << ' ' << BB << std::endl;
	}
	return 0;
}