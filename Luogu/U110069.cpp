//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans=-INF,a[101][101],sum[101][101],n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	for(int x2=1;x2<=n;++x2)
	{
		for(int y2=1;y2<=n;++y2)
		{
			for(int x1=0;x1<x2;++x1)
			{
				for(int y1=0;y1<y2;++y1)
				{
					ans=max(ans,sum[x2][y2]+sum[x1][y1]-sum[x1][y2]-sum[x2][y1]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

