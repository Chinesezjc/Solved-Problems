//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int h,n,a[1001],b[1001],dp[20001],ans=INF;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>h>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=h+10000;++i)
	{
		dp[i]=INF;
		for(int j=1;j<=n;++j)
		{
			if(i-a[j]<0)
			{
				continue;
			}
			dp[i]=min(dp[i],dp[i-a[j]]+b[j]);
		}
	}
	for(int i=h;i<=h+10000;++i)
	{
		ans=min(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}

