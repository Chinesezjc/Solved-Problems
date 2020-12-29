//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>c;
	if(a<=c)
	{
		cout<<0<<' '<<max(b+a-c,a-a);
	}
	else
	{
		cout<<a-c<<' '<<b;
	}
	return 0;
}

