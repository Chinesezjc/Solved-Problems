#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define mod 1000000007

using namespace std;
typedef long long ll;
const int MAXN = 50;
int f[MAXN];
ll n, lcm[MAXN], cnt[10];
inline ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
inline ll calc(ll l, ll r, ll x)
{
	return r / x - (l - 1) / x;
}
inline ll qpow(ll a, ll b)
{
	ll res = 1;
	for (; b; a = a * a % mod, b >>= 1ll)
		if (b & 1ll)
			res = res * a % mod;
	return res;
}

int main()
{
	cin >> n;
	f[2] = 1;
	for (int i = 3; i <= 50; i++)
		for (int j = 2; j < i; j++)
			if (i % j)
			{
				f[i] = f[j] + 1;
				break;
			}
	lcm[1] = 1;
	int pos = 2;
	for (pos = 2; pos <= 50; pos++)
	{
		lcm[pos] = lcm[pos - 1] * (pos / gcd(pos, lcm[pos - 1]));
		if (lcm[pos] > n)
			break;
	}
	for (int i = 2; i <= pos; i++)
		std::cout << calc(1, n, lcm[i - 1]) - calc(1, n, lcm[i]) << std::endl,
			cnt[f[i] + 1] += calc(1, n, lcm[i - 1]) - calc(1, n, lcm[i]);
	--cnt[f[2] + 1];
	--cnt[f[3] + 1];
	for (int i = 1; i <= 5; ++i)
		std::cout << cnt[i] << std::endl;
	ll ans = 1;
	for (int i = 2; i <= 5; i++)
		ans = ans * qpow(i, cnt[i]) % mod;
	cout << ans << endl;
	return 0;
}