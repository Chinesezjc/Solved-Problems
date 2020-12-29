//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,p,a[1001][1001],dp[1001],c[1001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	fill(dp+1,dp+1+m,-INF);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int l=j-1;
			if(!l)
			{
				l=n;
			}
			int sum=a[l][i];
			for(int k=1;k<=p;++k)
			{
				if(i-k<0)
				{
					break;
				}
				dp[i]=max(dp[i],dp[i-k]+sum-c[l--]);
				if(!l)
				{
					l=n;
				}
				sum+=a[l][i-k];
			}
		}
	}
	cout<<dp[m];
	return 0;
}

