//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,dp[101],ans;
struct C{
	int t,v;
	bool operator < (const C A)const
	{
		return t<A.t;
	}
}c[101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i].t;
		if(c[i].t>n)
		{
			c[i].t=n;
		}
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i].v;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;++i)
	{
		for(int j=c[i].t;j>0;--j)
		{
			dp[j]=max(dp[j],dp[j-1]+c[i].v);
		}
	}
	for(int i=1;i<=c[n].t;++i)
	{
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
}

