//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a,b,map[31][31],dis[31][31],xx[8],yy[8],ansx,ansy;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>map[i][j];
			if(map[i][j]!=3)
			{
				dis[i][j]=INF;
			}
			if(map[i][j]==4)
			{
				ansx=i;
				ansy=j;
			}
		}
	}
	xx[0]=a;yy[0]=b;
	xx[1]=b;yy[1]=a;
	xx[2]=b;yy[2]=-a;
	xx[3]=a;yy[3]=-b;
	xx[4]=-a;yy[4]=b;
	xx[5]=-b;yy[5]=a;
	xx[6]=-b;yy[6]=-a;
	xx[7]=-a;yy[7]=-b;
	for(int t=1;t<=n*m;++t)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(map[i][j]==2||map[i][j]==0)
				{
//					cout<<setw(4)<<(dis[i][j]==INF?-1:dis[i][j])<<' ';
					continue;
				}
				for(int I=0;I<8;++I)
				{
					int x=i+xx[I],y=j+yy[I];
					if(x<1||y<1||x>n||y>m)
					{
						continue;
					}
					dis[i][j]=min(dis[i][j],dis[x][y]+1);
				}
//				cout<<setw(4)<<(dis[i][j]==INF?-1:dis[i][j])<<' ';
			}
//			cout<<endl;
		}
//		cout<<endl;
	}
	cout<<dis[ansx][ansy];
	return 0;
}

