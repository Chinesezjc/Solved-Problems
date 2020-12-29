//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int h,ans=1;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>h;
	while(ans<=h)
	{
		ans<<=1;
	}
	cout<<ans-1;
	return 0;
}

