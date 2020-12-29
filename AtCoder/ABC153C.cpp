//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,h[200001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
	}
	sort(h+1,h+1+n);
	for(int i=n-k;i>0;--i)
	{
		ans+=h[i];
	}
	cout<<ans;
	return 0;
}

