#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define REP(i, n) for ((i) = 0; (i) < (int)(n); (i)++)
#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

typedef long long ll;
#define MOD 998244353ll

ll F[100010], inv[100010], Finv[100010];
ll G[100010];
int freq[100010];

int main(void)
{
	int i, j;

	inv[1] = 1;
	for (i = 2; i < 100010; i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

	F[0] = Finv[0] = 1;
	for (i = 1; i < 100010; i++)
	{
		F[i] = F[i - 1] * i % MOD;
		Finv[i] = Finv[i - 1] * inv[i] % MOD;
	}

	G[0] = 1;
	for (i = 1; i < 100010; i++)
		G[i] = G[i - 1] * (2 * i - 1) % MOD;

	int N;
	cin >> N;

	int h;
	REP(i, 2 * N)
	{
		scanf("%d", &h);
		freq[h]++;
	}

	deque<vector<ll>> P;

	REP(i, 100010)
	if (freq[i] > 0)
	{
		int n = freq[i];
		vector<ll> v(n / 2 + 1);
		REP(j, n / 2 + 1)
		{
			ll tmp = F[n] * Finv[2 * j] % MOD * Finv[n - 2 * j] % MOD * G[j] % MOD;
			if (j % 2 == 1)
				tmp = (MOD - tmp) % MOD;
			v[j] = tmp;
		}
		P.push_back(v);
	}

	while (P.size() > 1)
	{
		vector<ll> v = convolution(P[0], P[1]);
		P.pop_front();
		P.pop_front();
		P.push_back(v);
	}

	ll ans = 0;
	REP(i, P[0].size())
	ans = (ans + P[0][i] * G[N - i]) % MOD;
	cout << ans << endl;

	return 0;
}
