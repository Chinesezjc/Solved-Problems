//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int cnt,ans,a[100001],b[5000000],s,flag,n,x;
void run(int now)
{
	if(flag)
	{
		ans+=flag+now;
		if(flag+now<=100000)
		{
			++a[flag+now];
		}
		else
		{
			b[(++cnt)%5000000]=flag+now;
		}
		flag=0;
	}
	else
	{
		flag=now;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x;
		++a[x];
	}
	for(int i=1;i<=100000;++i)
	{
		while(a[i])
		{
			--a[i];
			run(i);
		}
	}
	for(int i=1;i<=cnt;++i)
	{
		run(b[i%5000000]);
	}
	cout<<ans;
	return 0;
}

