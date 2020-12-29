//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int h[100001],a,b,n,m,ans;
bool bad[100001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b;
		if(h[a]<=h[b])
		{
			bad[a]=true;
		}
		if(h[a]>=h[b])
		{
			bad[b]=true;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!bad[i])
		{
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}

