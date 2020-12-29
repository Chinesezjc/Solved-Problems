//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[31],dp[31][31],cho[31][31];
int dfs(int l,int r)
{
	if(dp[l][r])
	{
		return dp[l][r];
	}
	if(l>r)
	{
		return 1;
	}
	if(l==r)
	{
		return a[l];
	}
	for(int i=l;i<=r;++i)
	{
		if(dp[l][r]<dfs(l,i-1)*dfs(i+1,r)+a[i])
		{
			dp[l][r]=dfs(l,i-1)*dfs(i+1,r)+a[i];
			cho[l][r]=i;
		}
	}
	return dp[l][r];
}
void front(int l,int r)
{
	if(l>r)
	{
		return;
	}
	if(l==r)
	{
		cout<<l<<' ';
		return;
	}
	cout<<cho[l][r]<<' ';
	front(l,cho[l][r]-1);
	front(cho[l][r]+1,r);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cout<<dfs(1,n)<<endl;
	front(1,n);
	return 0;
}

