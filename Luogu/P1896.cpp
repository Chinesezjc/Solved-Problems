//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,dp[2][100][1<<10],have[1<<10],ans;
bool can[1<<10][1<<10];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	s=1<<n;
	for(int i=0;i<s;++i)
	{
		for(int j=0;j<s;++j)
		{
			can[i][j]=true;
			for(int k=0;k<n;++k)
			{
				if(i&(1<<k))
				{
					int l=k-1,r=k+1;
					if(l>=0)
					{
						if(i&(1<<l)||j&(1<<l))
						{
							can[i][j]=false;
							break;
						}
					}
					if(j&(1<<k))
					{
						can[i][j]=false;
						break;
					}
					if(r<n)
					{
						if(i&(1<<r)||j&(1<<r))
						{
							can[i][j]=false;
							break;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<s;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i&(1<<j))
			{
				++have[i];
			}
		}
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<s;++j)
		{
			if(!can[j][0])
			{
				continue;
			}
			for(int k=m;k>=have[j];--k)
			{
				dp[i&1][k][j]=0;
				for(int l=0;l<s;++l)
				{
					if(can[j][l])
					{
						dp[i&1][k][j]+=dp[(i-1)&1][k-have[j]][l];
					}
				}
			}
		}
	}
	for(int i=0;i<s;++i)
	{
		ans+=dp[n&1][m][i];
	}
	cout<<ans<<endl;
	return 0;
}

