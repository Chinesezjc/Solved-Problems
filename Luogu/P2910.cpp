//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s[101][101],a[10001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>s[i][j];
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	for(int i=2;i<=m;++i)
	{
		ans+=s[a[i-1]][a[i]];
	}
	cout<<ans<<endl;
	return 0;
}

