//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
double dp[24][8];
signed main()
{
	std::ios::sync_with_stdio(false);
	dp[1][1]=1;
	for(int i=2;i<=24;++i)
	{
		for(int j=1;j<=7;++j)
		{
			dp[i][j]=dp[i-1][j-1]*(7-j+1)/7+dp[i-1][j]*j/7;
		}
	}
	cout<<fixed<<setprecision(4)<<dp[13][7];
	return 0;
}

