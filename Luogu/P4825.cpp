//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 1000000007
using namespace std;
int v[101][101],dp[101][101],r,c,k;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>r>>c>>k;
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			cin>>v[i][j];
		}
	}
	dp[r][c]=1;
	for(int i=r;i>0;--i)
	{
		for(int j=c;j>0;--j)
		{
			for(int i1=i+1;i1<=r;++i1)
			{
				for(int j1=j+1;j1<=c;++j1)
				{
					if(v[i][j]!=v[i1][j1])
					{
						dp[i][j]+=dp[i1][j1];
						dp[i][j]%=MOD;
					}
				}
			}
		}
	}
	cout<<dp[1][1];
	return 0;
}

