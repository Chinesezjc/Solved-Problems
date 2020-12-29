//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,N,dp[501],w[200001],v[200001],a,b,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b>>c;
		for(int j=1;j<=a;j<<=1)
		{
			a-=j;
			++N;
			w[N]=j*b;
			v[N]=j*c;
		}
		if(a>0)
		{
			++N;
			w[N]=a*b;
			v[N]=a*c;
		}
	}
	for(int i=1;i<=N;++i)
	{
		for(int j=m;j>=w[i];--j)
		{
			dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}

