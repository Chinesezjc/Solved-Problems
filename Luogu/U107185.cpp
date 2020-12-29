//This code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int m,n,dis[801][801],x[801],y[801];
double ans=INF;
int w(int tmp)
{
	return tmp*tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
		for(int j=1;j<i;++j)
		{
			dis[i][j]=dis[j][i]=w(x[i]-x[j])+w(y[i]-y[j]);
		}
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
				dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			ans=min(ans,max((double)max(x[i],m-x[j]),sqrt(dis[i][j])/2));
		}
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}

