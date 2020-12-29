//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dis[201][201],c,m,n=200;
char a,b,ans='A';
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m;
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
	while(m)
	{
		cin>>a>>b>>c;
		dis[a][b]=min(c,dis[a][b]);
		dis[b][a]=min(c,dis[b][a]);
		--m;
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
				if(i==j||j==k)
				{
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(char i='B';i<'Z';++i)
	{
		if(dis[ans]['Z']>dis[i]['Z'])
		{
			ans=i;
		}
	}
	cout<<ans<<' '<<dis[ans]['Z']<<endl;
	return 0;
}

