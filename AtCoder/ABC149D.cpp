//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string t;
int n,k,w[3],a[100001],dp[3][100001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>w[1]>>w[2]>>w[0]>>t;
	for(int i=0;i<n;++i)
	{
		if(t[i]=='r')
		{
			a[i+1]=0;
		}
		if(t[i]=='s')
		{
			a[i+1]=1;
		}
		if(t[i]=='p')
		{
			a[i+1]=2;
		}
	}
	for(int i=1;i<=k;++i)
	{
		if(a[i]==0)
		{
			dp[0][i]=w[0];
			dp[1][i]=0;
			dp[2][i]=0;
		}
		if(a[i]==1)
		{
			dp[0][i]=0;
			dp[1][i]=w[1];
			dp[2][i]=0;
		}
		if(a[i]==2)
		{
			dp[0][i]=0;
			dp[1][i]=0;
			dp[2][i]=w[2];
		}
		for(int j=i+k;j<=n;j+=k)
		{
			if(a[j]==0)
			{
				dp[0][j]=max(dp[1][j-k],dp[2][j-k])+w[0];
				dp[1][j]=max(dp[0][j-k],dp[2][j-k]);
				dp[2][j]=max(dp[0][j-k],dp[1][j-k]);
			}
			if(a[j]==1)
			{
				dp[0][j]=max(dp[1][j-k],dp[2][j-k]);
				dp[1][j]=max(dp[0][j-k],dp[2][j-k])+w[1];
				dp[2][j]=max(dp[0][j-k],dp[1][j-k]);
			}
			if(a[j]==2)
			{
				dp[0][j]=max(dp[1][j-k],dp[2][j-k]);
				dp[1][j]=max(dp[0][j-k],dp[2][j-k]);
				dp[2][j]=max(dp[0][j-k],dp[1][j-k])+w[2];
			}
		}
	}
	for(int i=n;i+k>n;--i)
	{
		ans+=max(max(dp[0][i],dp[1][i]),dp[2][i]);
	}
	cout<<ans;
	return 0;
}

