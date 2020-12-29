//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,dp[250][250],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>dp[i][1];
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j+i-1<=n;++j)
		{
			for(int k=1;k<i;++k)
			{
				if(dp[j][k]==dp[j+k][i-k])
				{
					dp[j][i]=max(dp[j][i],dp[j][k]+1);
					ans=max(ans,dp[j][i]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

