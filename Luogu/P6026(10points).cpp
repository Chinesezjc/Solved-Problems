//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 1000000007
using namespace std;
int n,k,p[1001],l[1001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		p[i]=((MOD-MOD/i)*p[MOD%i])%MOD;
	}
	return 0;
}

