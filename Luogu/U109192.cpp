//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[1001][1001],b[1001],n,m,now,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				a[i][j]=-INF;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		fill(b+1,b+1+m,0);
		for(int j=i;j<=n;++j)
		{
			for(int k=1;k<=m;++k)
			{
				if(b[k]==-INF)
				{
					continue;
				}
				b[k]+=a[j][k];
				if(a[j][k]==-INF)
				{
					b[k]=-INF;
				}
			}
			now=0;
			for(int k=1;k<=m;++k)
			{
				now+=b[k];
				if(b[k]==-INF)
				{
					now=0;
				}
				else
				{
					now=max(0ll,now);
				}
				ans=max(now,ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

