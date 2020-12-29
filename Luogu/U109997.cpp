//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	m=1<<n;
	for(int i=0;i<m;++i)
	{
		for(int j=n;j;--j)
		{
			if(i&(1<<(j-1)))
			{
				putchar('1');
			}
			else
			{
				putchar('0');
			}
		}
		puts("");
	}
	return 0;
}

