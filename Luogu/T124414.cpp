//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,f[2049][2049],m,ans;
double dp[2][2049];
signed main()
{
	std::ios::sync_with_stdio(false);
//	freopen("")
	cin>>n;
	m=1<<n;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=m;++i)
	{
		dp[0][i]=100;
	}
	for(int i=1;i<=n;++i)
	{
		int I=1<<(i-1);
		for(int j=1;j<=m;++j)
		{
			dp[i&1][j]=0;
		}
		for(int j=I;j<m;j+=I<<1)
		{
			for(int k=1;k<=I;++k)
			{
				for(int l=1;l<=I;++l)
				{
					dp[i&1][j-I+k]+=dp[(i-1)&1][j-I+k]*dp[(i-1)&1][j+l]*f[j-I+k][j+l]/10000;
					dp[i&1][j+  l]+=dp[(i-1)&1][j-I+k]*dp[(i-1)&1][j+l]*f[j+l][j-I+k]/10000;
				}
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(dp[n&1][ans]<dp[n&1][i])
		{
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

