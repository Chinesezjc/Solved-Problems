//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a,s,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	s=INF;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		ans=max(a-s,ans);
		s=min(a,s);
	}
	cout<<ans;
	return 0;
}

