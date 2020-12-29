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
int l[501][501],dis[501],n,a,b,ans,nxt;
bool went[501];
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		dis[0]=INF;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cin>>l[i][j];
			}
			dis[i]=INF;
			went[i]=false;
		}
		dis[1]=0;
		nxt=1;
		for(int i=1;i<=n;++i)
		{
			went[nxt]=true;
			int now=nxt;
			nxt=0;
			for(int j=1;j<=n;++j)
			{
				dis[j]=min(dis[j],dis[now]+l[now][j]);
				if(!went[j]&&dis[j]<dis[nxt])
				{
					nxt=j;
				}
			}
		}
		ans=dis[n];
		a=b=INF;
		for(int i=2;i<n;++i)
		{
			a=min(a,dis[i]+l[i][1]);
		}
		for(int i=1;i<=n;++i)
		{
			dis[i]=INF;
			went[i]=false;
		}
		dis[n]=0;
		nxt=n;
		for(int i=1;i<=n;++i)
		{
			went[nxt]=true;
			int now=nxt;
			nxt=0;
			for(int j=1;j<=n;++j)
			{
				dis[j]=min(dis[j],dis[now]+l[now][j]);
				if(!went[j]&&dis[j]<dis[nxt])
				{
					nxt=j;
				}
			}
		}
		for(int i=2;i<n;++i)
		{
			b=min(b,dis[i]+l[i][n]);
		}
		for(int i=1;i<=n;++i)
		{
			dis[i]=INF;
			went[i]=false;
		}
		ans=min(a+b,ans);
		cout<<ans<<endl;
	}
	return 0;
}

