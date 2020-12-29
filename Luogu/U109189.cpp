//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[2002],ans;
int find(int now)
{
	int l=1,r=n+1,mid=(l+r)>>1;
	while(l<r)
	{
		if(a[mid]<=now)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
		mid=(l+r)>>1;
	}
	return mid;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[n+1]=INF;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			ans+=n+1-find(a[i]+a[j]);
		}
	}
	cout<<ans;
	return 0;
}

