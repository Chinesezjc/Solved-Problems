//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,s,t[200001],ans=1,vis[200001],now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i];
	}
	while((!vis[ans])&&k)
	{
		++now;
		vis[ans]=now;
		ans=t[ans];
		--k;
	}
	k%=now-vis[ans]+1;
	while(k)
	{
		ans=t[ans];
		--k;
	}
	cout<<ans<<endl;
	return 0;
}

