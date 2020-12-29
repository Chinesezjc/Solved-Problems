//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x;
bool a[2000000];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	n=1<<n;
	for(int i=1;i<n;++i)
	{
		cin>>x;
		a[x]=true;
	}
	for(int i=1;i<=n;++i)
	{
		if(!a[i])
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}

