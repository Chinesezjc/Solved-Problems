//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ans,s[1002],dp[1002];
struct boom{
	int a,b;
	bool operator<(const boom &A)const
	{
		return a==A.a?b<A.b:a>A.a;
	}
}a[1002];
int get(int now)
{
	if(s[now])
	{
		return s[now];
	}
	fill(dp+1,dp+1+now,0);
	for(int i=1;i<=n;++i)
	{
		for(int j=now;j;--j)
		{
			dp[j]=max(dp[j],dp[j-1]+a[i].a-a[i].b*(now-1));
		}
	}
	for(int i=1;i<=now;++i)
	{
		s[now]=max(dp[i],s[now]);
	}
	return s[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].a;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].b;
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(get(mid)<=get(mid+1))
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	cout<<get(l)<<endl<<l<<endl;
	return 0;
}

