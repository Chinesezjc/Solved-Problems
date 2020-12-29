//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[1000001],f[1000001],ans;
int find(int now,int l,int r)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[mid]<now)
		{
			l=mid+1;
		}
		if(a[mid]>now)
		{
			r=mid-1;
		}
		if(a[mid]==now)
		{
			return mid;
		}
	}
	if(a[l]!=now)
	{
		return 0;
	}
	else
	{
		return l;
	}
}
int dfs(int now)
{
	int A,B,tmp=0;
	if(f[now])
	{
		return f[now];
	}
	if(A=find(a[now]<<1,now+1,n))
	{
		tmp=max(tmp,dfs(A));
	}
	if(a[now]%3==0&&(B=find(a[now]/3,1,now-1)))
	{
		tmp=max(tmp,dfs(B));
	}
	return f[now]=tmp+1;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,dfs(i));
	}
	cout<<ans;
	return 0;
}

