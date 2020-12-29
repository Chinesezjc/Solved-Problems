//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m;
int item[40001],ans[4][15001],x[15001],sum[15001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>item[i];
		++x[item[i]];
	}
	for(int s3=1;9*s3<n;++s3)
	{
		int s1=2*s3;
		for(int i=1;i<=n-s3;++i)
		{
			sum[i]=sum[i-1]+x[i]*x[i+s3];
		}
		for(int i=1;i+9*s3<n;++i)
		{
			ans[0][i]+=(sum[n-s3]-sum[i+8*s3])*x[i+s1];
			ans[1][i+s1]+=(sum[n-s3]-sum[i+8*s3])*x[i];
		}
		for(int i=1;i<=n-s1;++i)
		{
			sum[i]=sum[i-1]+x[i]*x[i+s1];
		}
		for(int i=1;i+9*s3<n;++i)
		{
			ans[2][i+8*s3+1]+=sum[i]*x[i+9*s3+1];
			ans[3][i+9*s3+1]+=sum[i]*x[i+8*s3+1];
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[0][item[i]]<<' '<<ans[1][item[i]]<<' '<<ans[2][item[i]]<<' '<<ans[3][item[i]]<<endl;
	}
	return 0;
}

