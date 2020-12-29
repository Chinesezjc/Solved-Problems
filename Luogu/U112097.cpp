//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int xx[4]={1,0,-1,0},yy[4]={0,1,0,-1};
bool can[7][7][4];
int way[8],n,m,w,k,a,b,c,d;
char C[4]={'D','R','U','L'};
bool run()
{
	int nowx=n,nowy=1,nowt=-1;
	while(nowx!=1||nowy!=m)
	{
		++nowt;
		if(nowt>400)
		{
			return false;
		}
		if(can[nowx][nowy][way[nowt%k]])
		{
			continue;
		}
		nowx+=xx[way[nowt%k]];
		nowy+=yy[way[nowt%k]];
	}
	return true;
}
void dfsway(int now)
{
	if(now==k)
	{
		if(run())
		{
			for(int i=0;i<k;++i)
			{
				cout<<C[way[i]];
			}
			exit(0);
		}
		return;
	}
	way[now]=2;
	dfsway(now+1);
	way[now]=1;
	dfsway(now+1);
	way[now]=0;
	dfsway(now+1);
	way[now]=3;
	dfsway(now+1);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>w>>k;
	for(int i=1;i<=w;++i)
	{
		cin>>a>>b>>c>>d;
		for(int j=0;j<4;++j)
		{
			if(a+xx[j]==c&&b+yy[j]==d)
			{
				can[a][b][j]=true;
				can[c][d][j^2]=true;
				break;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		can[1][i][2]=can[n][i][0]=true;
	}
	for(int i=1;i<=n;++i)
	{
		can[i][1][3]=can[i][m][1]=true;
	}
	dfsway(0);
	return 0;
}

