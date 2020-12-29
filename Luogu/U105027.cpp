//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
bool went[102][102];
int n,m,now,a,b,k,ans,l,r;
struct DL{
	int x,y;
}dl[10001];
void bfs(int x,int y)
{
	++now;
	for(int i=0;i<4;++i)
	{
		if(!(x+xx[i]==0||x+xx[i]==n+1||y+yy[i]==0||y+yy[i]==m+1)&&went[x+xx[i]][y+yy[i]])
		{
			went[x+xx[i]][y+yy[i]]=false;
			++r;
			dl[r].x=x+xx[i];
			dl[r].y=y+yy[i];
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	while(k)
	{
		--k;
		cin>>a>>b;
		went[a][b]=true;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(went[i][j])
			{
				now=0;
				went[i][j]=false;
				++r;
				dl[r].x=i;
				dl[r].y=j;
				while(l<r)
				{
					++l;
					bfs(dl[l].x,dl[l].y);
				}
				ans=max(now,ans);
			}
		}
	}
	cout<<ans;
	return 0;
}

