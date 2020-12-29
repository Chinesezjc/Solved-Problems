//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[1000001],l,r;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>l>>r;
		++a[l];
		--a[r+1];
	}
	for(int i=1;i<=n;++i)
	{
		a[i]+=a[i-1];
	}
	sort(a+1,a+1+n);
	cout<<a[(n+1)>>1];
	return 0;
}

