//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 10000007
using namespace std;
int n,dp[50],ans=1,have;
int sum(int now)
{
	int s=0;
	for(int i=1;i<=now;i<<=1)
	{
		if(i&now)
		{
			++s;
		}
	}
	return s;
}
int power(int a,int b,int c)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=(tmp*a)%c;
		}
		a=(a*a)%c;
		b>>=1;
	}
	return tmp;
}
void work(int now)
{
	int d[50];
	fill(d,d+50,0);
	d[have]=1;
	for(int i=0;i<=now;++i)
	{
		for(int j=49;j>=1;--j)
		{
			d[j]+=d[j-1];
		}
	}
	for(int i=0;i<50;++i)
	{
		dp[i]+=d[i];
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	++n;
	for(int i=50;i>=0;--i)
	{
		if(n&(1ll<<i))
		{
			work(i-1);
			++have;
		}
	}
	for(int i=2;i<50;++i)
	{
		ans=(ans*power(i,dp[i],MOD))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}

