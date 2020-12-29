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
int n,k,m,tmp,ans;
bool good[101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=k;++i)
	{
		cin>>m;
		for(int l=1;l<=m;++l)
		{
			cin>>tmp;
			good[tmp]=true;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!good[i])
		{
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}

