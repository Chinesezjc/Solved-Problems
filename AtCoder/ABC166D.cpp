//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int x;
int _5(int now)
{
	return now*now*now*now*now;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>x;
	for(int i=-200;i<=200;++i)
	{
		for(int j=-200;j<=200;++j)
		{
			if(_5(i)-_5(j)==x)
			{
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}

