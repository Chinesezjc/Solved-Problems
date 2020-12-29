//This code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int m,n,a,b;
double x,y,dp[1001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n>>a>>b>>x>>y;
	dp[m]=max(a,b);
	for(int i=m-1;i;--i)
	{
		dp[i]=max(a+dp[i+1]*(1-x),b+dp[i+1]*(1-y));
	}
	cout<<fixed<<setprecision(5)<<n*dp[1];
	return 0;
}

