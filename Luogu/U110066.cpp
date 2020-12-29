//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,Min,a[1001];
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0)
		{
			return 0;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		Min=1;
		for(int i=2;i<=n;++i)
		{
			if(a[Min]>a[i])
			{
				Min=i;
			}
		}
		swap(a[Min],a[1]);
		for(int i=1;i<=n;++i)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

