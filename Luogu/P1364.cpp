//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3ffffffffffffff
using namespace std;
int n,p[101],dis[101][101],now,ans,to;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;++i)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>p[i];
		cin>>to;
		dis[i][to]=1;
		dis[to][i]=1;
		cin>>to;
		dis[i][to]=1;
		dis[to][i]=1;
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==k)
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				if(j==i||j==k)
				{
					continue;
				}
				dis[j][i]=dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	ans=INF;
	for(int i=1;i<=n;++i)
	{
		now=0;
		for(int j=1;j<=n;++j)
		{
			now+=dis[j][i]*p[j];
		}
		ans=min(now,ans);
	}
	cout<<ans;
	return 0;
}

