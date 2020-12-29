//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int tong[101],tmp,n;
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0)
		{
			return 0;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>tmp;
			++tong[tmp];
		}
		for(int i=1;i<=100;++i)
		{
			while(tong[i])
			{
				--tong[i];
				--n;
				cout<<i<<" \n"[n==0];
			}
		}
	}
	return 0;
}

