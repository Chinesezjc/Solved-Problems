//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int m,a[7],c[7]={0,1,2,3,5,10,20},ans;
bool dp[1001];
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=6;++i)
	{
		cin>>a[i];
	}
	cout<<"Total=";
	dp[0]=true;
	for(int i=1;i<=6;++i)
	{
		for(int j=1;j<=a[i];++j)
		{
			m+=c[i];
			for(int k=m;k>=c[i];--k)
			{
				dp[k]=dp[k]||dp[k-c[i]];
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(dp[i])
		{
			++ans;
		}
	}
	cout<<ans;
	return 0;
}

