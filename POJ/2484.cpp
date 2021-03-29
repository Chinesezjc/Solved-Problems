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
	while(true)
	{
		cin>>n;
		if(n==0)
		{
			return 0;
		}
		cout<<(n<=2?"Alice":"Bob")<<endl;
	}
	return 0;
}

