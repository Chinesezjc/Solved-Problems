//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dp[101][1001],d,g,ans;
struct S{
	int t,x,y;
	bool operator < (const S tmp)const
	{
		return t<tmp.t;
	}
}s[101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>d>>g;
	for(int i=1;i<=g;++i)
	{
		cin>>s[i].t>>s[i].x>>s[i].y;
	}
	for(int i=0;i<=g;++i)
	{
		fill(dp[i],dp[i]+1001,-INF);
	}
	dp[0][10]=0;
	sort(s+1,s+1+g);
	for(int i=1;i<=g;++i)
	{
		for(int j=1000;j>=s[i].t;--j)
		{
			if(j-s[i].x>=s[i].t)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-s[i].x]);
			}
			dp[i][j]=max(dp[i][j],dp[i-1][j]+s[i].y);
		}
	}
	for(int i=1;i<=g;++i)
	{
		for(int j=s[i].t;j<=1000;++j)
		{
			if(dp[i][j]>=d)
			{
				cout<<s[i].t<<endl;
				return 0;
			}
		}
	}
	ans=10;
	for(int i=1;i<=g;++i)
	{
		if(ans>=s[i].t)
		{
			ans+=s[i].x;
		}
	}
	cout<<ans;
	return 0;
}

