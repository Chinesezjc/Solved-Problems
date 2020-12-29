//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,dp[2][1024][1024],ans,have[1024],can[105];
bool good[1024];
char c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	s=1<<m;
	for(int i=2;i<=n+1;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>c;
			if(c=='P')
			{
				can[i]|=1<<j;
			}
		}
	}
	for(int i=0;i<s;++i)
	{
		good[i]=true;
		for(int j=0;j<m;++j)
		{
			if(i&(1<<j))
			{
				++have[i];
				if(i&(1<<(j+1))||i&(1<<(j+2)))
				{
					good[i]=false;
					break;
				}
			}
		}
	}
	for(int i=2;i<=n+1;++i)
	{
		for(int j=0;j<s;++j)
		{
			if(!good[j]||(j|can[i-1])!=can[i-1])
			{
				continue;
			}
			for(int k=0;k<s;++k)
			{
				if(!good[k]||(k|can[i])!=can[i]||(j|k)!=j+k)
				{
					continue;
				}
				dp[i&1][j][k]=0;
				for(int l=0;l<s;++l)
				{
					if(!good[l]||(l|can[i-2])!=can[i-2]||(j|k|l)!=j+k+l)
					{
						continue;
					}
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][l][j]+have[k]);
				}
			}
		}
	}
	for(int i=0;i<s;++i)
	{
		if(!good[i]||(i|can[n])!=can[n])
		{
			continue;
		}
		for(int j=0;j<s;++j)
		{
			if(!good[j]||(j|can[n+1])!=can[n+1]||(i|j)!=i+j)
			{
				continue;
			}
			ans=max(ans,dp[(n+1)&1][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

