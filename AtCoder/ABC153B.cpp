//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,n,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>n;
	while(n)
	{
		--n;
		cin>>b;
		a-=b;
	}
	if(a>0)
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
	return 0;
}

