//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3ffffff//fffffffff
using namespace std;
int n,a[101],up[101],down[101],ans=INF;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i-1;j>up[i];--j)
		{
			if(a[i]>a[j])
			up[i]=max(up[i],up[j]);
		}
		++up[i];
	}
	for(int i=n;i>0;--i)
	{
		for(int j=i+1;j<=n-down[i];++j)
		{
			if(a[i]>a[j])
			down[i]=max(down[i],down[j]);
		}
		++down[i];
	}
	for(int i=1;i<=n;++i)
	{
		ans=min(n-(up[i]+down[i]-1),ans);
	}
	cout<<ans;
	return 0;
}

