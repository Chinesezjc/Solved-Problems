//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,s,dp[10001],w;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s;
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>w;
		for(int j=w;j<=s;++j)
		{
			dp[j]+=dp[j-w];
		}
	}
	cout<<dp[s];
	return 0;
}

