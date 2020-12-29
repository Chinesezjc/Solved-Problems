//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,h,v[51],ans=INF,sum[51];
void dfs(int i,int now)
{
	if(now>=h)
	{
		ans=min(ans,now);
		return;
	}
	if(i==n||now+sum[n]-sum[i]<h)
	{
		return;
	}
	dfs(i+1,now);
	dfs(i+1,now+v[i+1]);
}
bool cmp(const int A,const int B)
{
	return A>B;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>h;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	sort(v+1,v+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+v[i];
	}
	dfs(0,0);
	cout<<ans-h;
	return 0;
}
