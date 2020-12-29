//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
char map[1001][1001];
int n,num[1001][1001],ans[1000001],cnt,x[2][1000001],y[2][1000001],cnts[2],maxx,maxy;
const int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
bool went[1001][1001];
int bfs2(int a,int b)
{
	cnts[1]=1;
	x[1][1]=a;
	y[1][1]=b;
	num[a][b]=1;
	for(int now=1;cnts[now&1];++now)
	{
		cnts[(now+1)&1]=0;
		for(int i=1;i<=cnts[now&1];++i)
		{
			maxx=x[now&1][i];
			maxy=y[now&1][i];
			for(int j=0;j<4;++j)
			{
				if(map[maxx+xx[j]][maxy+yy[j]]=='1'&&!num[maxx+xx[j]][maxy+yy[j]])
				{
					++cnts[(now+1)&1];
					x[(now+1)&1][cnts[(now+1)&1]]=maxx+xx[j];
					y[(now+1)&1][cnts[(now+1)&1]]=maxy+yy[j];
					num[maxx+xx[j]][maxy+yy[j]]=num[maxx][maxy]+1;
				}
			}
		}
	}
	return num[maxx][maxy];
}
int bfs1(int a,int b)
{
	cnts[1]=1;
	x[1][1]=a;
	y[1][1]=b;
	went[a][b]=true;
	for(int now=1;cnts[now&1];++now)
	{
		cnts[(now+1)&1]=0;
		for(int i=1;i<=cnts[now&1];++i)
		{
			maxx=x[now&1][i];
			maxy=y[now&1][i];
			for(int j=0;j<4;++j)
			{
				if(map[maxx+xx[j]][maxy+yy[j]]=='1'&&!went[maxx+xx[j]][maxy+yy[j]])
				{
					++cnts[(now+1)&1];
					x[(now+1)&1][cnts[(now+1)&1]]=maxx+xx[j];
					y[(now+1)&1][cnts[(now+1)&1]]=maxy+yy[j];
					went[maxx+xx[j]][maxy+yy[j]]=true;
				}
			}
		}
	}
	return bfs2(maxx,maxy);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(map[i][j]=='1'&&!num[i][j])
			{
				ans[++cnt]=bfs2(i,j);
			}
		}
	}
	cout<<cnt<<endl;
	sort(ans+1,ans+1+cnt);
	for(int i=1;i<=cnt;++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

