//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,a[17],w[100002],sum[100001],leave[1<<16],has[1<<16],dp[1<<16],ans,SUM;
int find(int l,int r,int now)
{
	if(l>m)
	{
		return m;
	}
	int start=l-1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(sum[mid]-sum[start]<=now)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	s=1<<n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		SUM+=a[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
		sum[i]=sum[i-1]+w[i];
	}
	w[m+1]=INF;
	sum[m+1]=sum[m]+w[m+1];
	for(int i=0;i<s;++i)
	{
		leave[i]=SUM;
		for(int j=0;j<n;++j)
		{
			if(i&(1<<j))
			{
				leave[i]-=a[j+1];
				++has[i];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<s;++j)
		{
			if(has[j]==i)
			{
				for(int k=0;k<n;++k)
				{
					if(j&(1<<k))
					{
						dp[j]=max(dp[j],find(dp[j^(1<<k)]+1,m,a[k+1]));
					}
				}
			}
		}
	}
	ans=-1;
	for(int i=0;i<s;++i)
	{
		if(dp[i]==m)
		{
			ans=max(leave[i],ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}

