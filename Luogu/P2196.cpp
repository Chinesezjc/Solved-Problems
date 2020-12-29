//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[25],to[25][25],dp[25],from[25],ans,n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			cin>>to[i][j];
		}
	}
	dp[n]=a[n];
	for(int i=n-1;i;--i)
	{
		dp[i]=a[i];
		for(int j=i+1;j<=n;++j)
		{
			if(to[i][j]&&dp[i]<dp[j]+a[i])
			{
				dp[i]=dp[j]+a[i];
				from[i]=j;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(dp[i]>dp[ans])
		{
			ans=i;
		}
	}
	for(int i=ans;i;i=from[i])
	{
		cout<<i<<' ';
	}
	cout<<endl<<dp[ans]<<endl;
	return 0;
}

