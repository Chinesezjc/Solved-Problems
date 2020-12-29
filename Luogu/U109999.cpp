//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
void write(int now)
{
	if(now/8)
	{
		write(now/8);
	}
	putchar(now%8+'0');
}
int n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	write(n);
	return 0;
}

