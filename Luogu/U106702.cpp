//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,T,a[101],d[101][101],c[101],t[101],dp[10001][101],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>T;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i]>>t[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>d[i][j];
		}
	}
	for(int i=1;i<=T;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				if(j==k||a[j]<=a[k]||i-d[k][j]-t[j]<0)
				{
					continue;
				}
				dp[i][j]=max(dp[i][j],dp[i-d[k][j]-t[j]][k]+c[j]);
			}
			ans=max(dp[i][j],ans);
		}
	}
	cout<<ans;
	return 0;
}

