//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,b[601],dp[301];
string s,a[601];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[i]=a[i].length();
		a[i]=' '+a[i];
	}
	s=' '+s;
	for(int i=1;i<=m;++i)
	{
		dp[i]=dp[i-1]+1;
		for(int j=1;j<=n;++j)
		{
			int now=b[j],k=i;
			while(k>0&&now>0)
			{
				if(s[k]==a[j][now])
				{
					--now;
				}
				--k;
			}
			if(now==0)
			{
				dp[i]=min(dp[i],dp[k]+i-k-b[j]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}

