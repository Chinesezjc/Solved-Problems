//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ans,now,nex,divs,dis[2001];
string a[2001];
bool went[2001];
int s(int X,int Y)
{
	int tmp=0;
	for(int i=0;i<7;++i)
	{
		if(a[X][i]!=a[Y][i])
		{
			++tmp;
		}
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0)
		{
			break;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		fill(went+1,went+1+n,false);
		fill(dis+1,dis+1+n,INF);
		nex=1;
		ans=0;
		for(int i=1;i<n;++i)
		{
			now=nex;
			went[now]=true;
			divs=INF;
			for(int j=1;j<=n;++j)
			{
				if(!went[j])
				{
					dis[j]=min(dis[j],s(now,j));
					if(dis[j]<divs)
					{
						divs=dis[j];
						nex=j;
					}
				}
			}
			ans+=divs;
		}
		cout<<"1/"<<ans<<endl;
	}
	return 0;
}

