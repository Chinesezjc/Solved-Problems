//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans,m=3000000,tmp;
signed main()
{
	std::ios::sync_with_stdio(false);
	while(m)
	{
		--m;
		cin>>tmp;
		ans^=tmp;
	}
	cout<<ans;
	return 0;
}

