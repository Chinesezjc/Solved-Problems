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
int n,k,a[200002],b[200002];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int j=1;j<=k;++j)
	{
		for(int i=1;i<=n;++i)
		{
			++b[max(1ll,i-a[i])];
			--b[min(n+1,i+a[i]+1)];
		}
		for(int i=1;i<=n;++i)
		{
			a[i]=b[i]+a[i-1];
			b[i]=0;
		}
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(a[i]!=n)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}

