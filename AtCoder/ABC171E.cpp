//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[200001],b[200001],now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<=30;++i)
	{
		now=0;
		for(int j=1;j<=n;++j)
		{
			now^=a[j]&(1<<i);
		}
		for(int j=1;j<=n;++j)
		{
			b[j]|=now^(a[j]&(1<<i));
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}

