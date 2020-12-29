//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int m,n,c[102][102],dis[102][102];
const int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
void dfs(int x,int y,int color,int now)
{
	if(x<1||x>m||y<1||y>m)
	{
		return;
	}
	if(c[x][y])
	{
		if(now>=dis[x][y])
		{
			return;
		}
		dis[x][y]=now;
	}
	if(x==m&&y==m)
	{
		dis[x][y]=min(dis[x][y],now);
		return;
	}
	for(int i=0;i<4;++i)
	{
		if(!c[x][y])
		{
			if(c[x+xx[i]][y+yy[i]])
			{
				if(c[x+xx[i]][y+yy[i]]!=color)
				{
					dfs(x+xx[i],y+yy[i],c[x+xx[i]][y+yy[i]],now+1);
				}
				else
				{
					dfs(x+xx[i],y+yy[i],c[x+xx[i]][y+yy[i]],now);
				}
			}
		}
		else
		{
			if(c[x+xx[i]][y+yy[i]])
			{
				if(c[x+xx[i]][y+yy[i]]!=color)
				{
					dfs(x+xx[i],y+yy[i],c[x+xx[i]][y+yy[i]],now+1);
				}
				else
				{
					dfs(x+xx[i],y+yy[i],c[x+xx[i]][y+yy[i]],now);
				}
			}
			else
			{
				dfs(x+xx[i],y+yy[i],c[x][y],now+2);
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		c[x][y]=z+1;
	}
	for(int i=1;i<=m;++i)
	{
		fill(dis[i]+1,dis[i]+1+m,INF);
	}
	dfs(1,1,c[1][1],0);
	cout<<(dis[m][m]==INF?-1:dis[m][m]);
	return 0;
}

