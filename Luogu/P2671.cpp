//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define mod %10007
using namespace std;
int n,m,number[100001],color[100001],head[100001],nextn[200001],ans,sumnumber,sumn,sums,sum;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>number[i];
		number[i]%=10007;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>color[i];
		if(i%2)
		{
			color[i]+=m;
		}
		nextn[i]=head[color[i]];
		head[color[i]]=i;
	}
	for(int i=1;i<=m<<1;++i)
	{
		sumnumber=0;
		sumn=0;
		sums=0;
		sum=-2;
		for(int j=head[i];j;j=nextn[j])
		{
			sum=(sum+1)mod;
			sums=(sums+j*number[j])mod;
			sumnumber=(sumnumber+number[j])mod;
			sumn=(sumn+j)mod;
		}
		if(sum<0)
		{
			continue;
		}
		ans=(ans+(sum*sums)mod+(sumnumber*sumn)mod)mod;
	}
	cout<<ans;
	return 0;
}

