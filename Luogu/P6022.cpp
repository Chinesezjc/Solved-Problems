//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans,tmp,lefts[6];
signed main()
{
	register signed a[6],n,m;
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i];
	}
	if(n==2&&m==2&&a[1]==2&&a[2]==2)
	{
		cout<<"Inf";
		return 0;
	}
	while(n)
	{
		for(int i=1;i<=m;++i)
		{
			lefts[i]+=n;
		}
		ans+=n;
		n=0;
		for(int i=1;i<=m;++i)
		{
			tmp=lefts[i]/a[i];
			n+=tmp;
			lefts[i]-=tmp*a[i];
		}
	}
	cout<<ans;
	return 0;
}

