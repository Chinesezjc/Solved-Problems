//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans[21],n,m,a;
int geth(int now)
{
	int ANS=0;
	for(int i=0;i<a;++i)
	{
		ANS=max(ANS,ans[i+now]);
	}
	return ANS;
}
int get()
{
	int h=INF,ANS;
	for(int i=1;i+a-1<=m;++i)
	{
		int tmp=geth(i);
		if(tmp<h)
		{
			ANS=i;
			h=tmp;
		}
	}
	return ANS;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		int from=get(),to=from+a-1,high=geth(from);
		for(int i=from;i<=to;++i)
		{
			ans[i]=high+a;
		}
	}
	a=m;
	cout<<geth(1);
	return 0;
}

