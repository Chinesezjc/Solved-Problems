//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
bool L(int n)
{
	for(int i=2;i*i<=n;++i)
	{
		if(!(n%i))
		{
			return false;
		}
	}
	return true;
}
int a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a;
	for(int i=a;true;++i)
	{
		if(L(i))
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}

