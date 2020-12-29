//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[1001],dp[1001][1001];
int dfs(int l,int r)
{
	if(dp[l][r])
	{
		return dp[l][r];
	}
	if(l+1==r)
	{
		return dp[l][r]=max(a[l]*a[r+1],a[l-1]*a[r])+a[l-1]*a[r+1];
	}
	if(l==r)
	{
		return dp[l][r]=a[l-1]*a[r+1];
	}
	int tmp=max(dfs(l+1,r),dfs(l,r-1));
	for(int i=l+1;i<r;++i)
	{
		tmp=max(tmp,dfs(l,i-1)+dfs(i+1,r));
	}
	return dp[l][r]=tmp+a[l-1]*a[r+1];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<dfs(2,n-1);
	return 0;
}

