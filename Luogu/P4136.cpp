//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
signed main()
{
	std::ios::sync_with_stdio(false);
	do
	{
		cin>>n;
		if(n)
		{
			cout<<(n&1?"Bob":"Alice")<<endl;
		}
	}
	while(n);
	return 0;
}

