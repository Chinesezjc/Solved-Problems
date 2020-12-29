//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct l{
	int a,b;
	bool operator < (const l &tmp)const
	{
		return a<tmp.a;
	}
}s[101];
int dp[400001],n,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i].a>>s[i].b;
	}
	sort(s+1,s+1+n);
	fill(dp,dp+400001,-INF);
	dp[200000]=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i].a>0)
		{
			for(int j=300000;j>=s[i].a;--j)
			{
				dp[j]=max(dp[j],dp[j-s[i].a]+s[i].b);
			}
		}
		else
		{
			for(int j=100000;j<=300000;++j)
			{
				dp[j]=max(dp[j],dp[j-s[i].a]+s[i].b);
			}
		}
	}
	for(int i=200000;i<=300000;++i)
	{
		if(dp[i]<0)
		{
			continue;
		}
		ans=max(dp[i]+i-200000,ans);
	}
	cout<<ans;
	return 0;
}

