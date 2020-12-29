//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int lef,mid,rig,l,r,n,d,q,que[500002],x[500001],v[500001],dp[500001],sum;
int work()
{
	int i=0,j=0,a=max(i+1,d-mid),b=d+mid;
	fill(dp+1,dp+1+n,-INF);
	l=1;r=0;
	while(i<n)
	{
		++i;
		while(x[j]<=x[i]-a)
		{
			while(l<=r&&dp[j]>=dp[que[r]])
			{
				--r;
			}
			que[++r]=j;
			++j;
		}
		while(l<=r&&x[que[l]]<x[i]-b)
		{
			++l;
		}
		if(l<=r)
		{
			dp[i]=v[i]+dp[que[l]];
		}
	}
	l=-INF;
	for(i=1;i<=r;++i)
	{
		l=max(dp[que[i]],l);
	}
	return l;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>d>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>v[i];
		if(v[i]>0)
		{
			sum+=v[i];
		}
	}
	if(sum<q)
	{
		cout<<"-1";
		return 0;
	}
	lef=0;
	rig=max(x[n]-d,d);
	while(lef<rig)
	{
		mid=(lef+rig)>>1;
		if(work()>=q)
		{
			rig=mid;
		}
		else
		{
			lef=mid+1;
		}
	}
	cout<<lef;
	return 0;
}

