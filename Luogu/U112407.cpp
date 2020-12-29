//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int k,n,two[201],five[201],tmp,dp[201][5001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>tmp;
		while(tmp%2==0)
		{
			++two[i];
			tmp/=2;
		}
		while(tmp%5==0)
		{
			++five[i];
			tmp/=5;
		}
	}
	for(int i=0;i<=k;++i)
	{
		fill(dp[i],dp[i]+5001,-INF);
	}
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=min(i,k);j>0;--j)
		{
			for(int K=5000;K>=five[i];--K)
			{
				dp[j][K]=max(dp[j][K],dp[j-1][K-five[i]]+two[i]);
			}
		}
	}
	for(int i=0;i<=5000;++i)
	{
		ans=max(ans,min(i,dp[k][i]));
	}
	cout<<ans<<endl;
	return 0;
}

