//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,ans,num[16],que[100001];
void dfs(int now,int sum)
{
	ans+=n/sum;
	for(++now;now<=m;++now)
	{
		dfs(now,sum*num[now]/__gcd(abs(sum),num[now])*-1);
	}
}
void mainn()
{
	for(int i=1;i<=m;++i)
	{
		cin>>num[i];
	}
	ans=0;
	dfs(0,1);
	cout<<ans<<endl;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		mainn();
	}
	return 0;
}

