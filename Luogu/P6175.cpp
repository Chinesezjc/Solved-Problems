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
#define INF 0x3ffffffffffffff
using namespace std;
int n,m,s[101][101],start[101][101],ans=INF,a,b,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			s[i][j]=INF;
		}
		s[i][i]=0;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		if(s[a][b]>c)
		{
			s[a][b]=s[b][a]=c;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			start[i][j]=s[i][j];
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<k;++i)
		{
			for(int j=1;j<k;++j)
			{
				if(i==j||j==k||k==i)
				{
					continue;
				}
				ans=min(ans,start[j][k]+start[k][i]+s[i][j]);
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	if(ans>=INF)
	{
		cout<<"No solution."<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}

