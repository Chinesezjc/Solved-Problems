//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 100000000
using namespace std;
int n,m,g[13],dp[2][400],s,cnt,ans,good[1<<12];
char c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>c;
			if(c=='1')
			{
				g[i]|=1<<j;
			}
		}
	}
	s=1<<m;
	for(int i=0;i<s;++i)
	{
		good[++cnt]=i;
		for(int j=1;j<m;++j)
		{
			if((i&(1<<j))&&(i&(1<<(j-1))))
			{
				--cnt;
				break;
			}
		}
	}
	dp[0][1]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=cnt;++j)
		{
			dp[i&1][j]=0;
			if((good[j]|g[i])!=g[i])
			{
				continue;
			}
			for(int k=1;k<=cnt;++k)
			{
				if((good[k]|g[i-1])!=g[i-1]||(good[j]&good[k]))
				{
					continue;
				}
				dp[i&1][j]+=dp[!(i&1)][k];
			}
			dp[i&1][j]%=MOD;
		}
	}
	for(int i=1;i<=cnt;++i)
	{
		ans+=dp[n&1][i];
	}
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}

