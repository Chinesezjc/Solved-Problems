//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,h,v[21],ans=INF;
void dfs(int i,int now)
{
	if(now>=h)
	{
		ans=min(ans,now);
		return;
	}
	if(i==n)
	{
		return;
	}
	dfs(i+1,now);
	dfs(i+1,now+v[i+1]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>h;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	dfs(0,0);
	cout<<ans-h;
	return 0;
}

