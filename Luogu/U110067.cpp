//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[10001],now,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	now=1;
	for(int i=2;i<=m;++i)
	{
		if(a[i]==a[i-1])
		{
			++now;
		}
		else
		{
			if(now>m/2)
			{
				cout<<a[i-1]<<endl;
				return 0;
			}
			now=1;
		}
	}
	if(now>m/2)
	{
		cout<<a[m]<<endl;
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
}

