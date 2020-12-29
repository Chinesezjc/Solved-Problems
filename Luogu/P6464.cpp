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
int n,m,s[101][101],a,b,c,ans=INF,tmp[101][101];
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
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		s[a][b]=s[b][a]=c;
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
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int now=0;
			for(int I=1;I<=n;++I)
			{
				for(int J=1;J<=n;++J)
				{
					tmp[I][J]=s[I][J];
				}
			}
			tmp[i][j]=tmp[j][i]=0;
			for(int I=1;I<=n;++I)
			{
				for(int J=1;J<=n;++J)
				{
					tmp[I][J]=min(tmp[I][J],tmp[I][i]+tmp[i][J]);
				}
			}
			for(int I=1;I<=n;++I)
			{
				for(int J=1;J<=n;++J)
				{
					tmp[I][J]=min(tmp[I][J],tmp[I][j]+tmp[j][J]);
				}
			}
			for(int I=1;I<=n;++I)
			{
				for(int J=1;J<I;++J)
				{
					now+=tmp[I][J];
				}
			}
			ans=min(now,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}

