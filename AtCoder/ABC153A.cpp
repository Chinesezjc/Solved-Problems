//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>b>>a;
	cout<<(b/a+(b%a>0));
	return 0;
}

