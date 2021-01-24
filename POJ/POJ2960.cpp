//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,k,a[101],x,b[10001],ans,Max;
bool s[101];
int un()
{
	for(int i=0;i<=100;++i)
	{
		if(s[i])
		{
			return i;
		}
	}
	return -1;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(true)
	{
		ans=0;
		cin>>n;
		if(!n)
		{
			return 0;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int i=1;i<=10000;++i)
		{
			fill(s,s+101,true);
			for(int j=1;j<=n;++j)
			{
				if(i-a[j]>=0)
				{
					s[b[i-a[j]]]=false;
				}
			}
			b[i]=un();
		}
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			cin>>k;
			for(int j=1;j<=k;++j)
			{
				cin>>x;
				ans^=b[x];
			}
			cout<<(ans?'W':'L');
			ans=0;
		}
		cout<<endl;
	}
	return 0;
}

