//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[10001],dp[10001],sum[10001],n,m;
int Abs(int tmp)
{
	return tmp>0?tmp:-tmp;
}
int D(int l,int r)
{
	int mid=(l+r)>>1;
	return a[mid]*(mid-l-r+mid)-sum[mid-1]+sum[l-1]+sum[r]-sum[mid];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	fill(dp+1,dp+1+n,INF);
	for(int i=1;i<=m;++i)
	{
		for(int j=n;j>=i;--j)
		{
			for(int k=i-1;k<j;++k)
			{
				dp[j]=min(dp[j],dp[k]+D(k+1,j));
			}
		}
	}
	cout<<dp[n];
	return 0;
}

