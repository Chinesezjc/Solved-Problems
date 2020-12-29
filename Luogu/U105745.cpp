//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int h,n,a[65536],now,ans[65536];
void build(int p,int l)
{
	if(l==h+1)
	{
		return;
	}
	ans[p]=a[++now];
	build(p<<1|1,l+1);
	build(p<<1,l+1);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(1<<h<=n)
	{
		++h;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	build(1,1);
	for(int i=1;i<=n;++i)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

