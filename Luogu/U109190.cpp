//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[31],b[31],c[31],d[31],n,m,dp[1200000];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=0;--j)
		{
			if(j>=d[i])
			{
				dp[j]=max(dp[j],dp[j-d[i]]+c[i]);
			}
			if(j>=b[i])
			{
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}

