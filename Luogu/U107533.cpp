//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans[51],n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	ans[1]=2;
	ans[2]=3;
	for(int i=3;i<=n;++i)
	{
		ans[i]=ans[i-1]+ans[i-2];
	}
	cout<<ans[n];
	return 0;
}

