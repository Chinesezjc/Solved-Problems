//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[101],dp[101][101];
int dfs(int l,int r)
{
	if(dp[l][r])
	{
		return dp[l][r];
	}
	if(l==r)
	{
		return a[l];
	}
	if(l>r)
	{
		return 0;
	}
	int now=max(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
	for(int i=l+1;i<=r;++i)
	{
		now=max(now,dfs(i+1,r)+(i-l+1)*abs(a[i]-a[l]));
	}
	for(int i=r-1;i>=l;--i)
	{
		now=max(now,dfs(l,i-1)+(r-i+1)*abs(a[i]-a[r]));
	}
	return dp[l][r]=now;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<dfs(1,n);
	return 0;
}

