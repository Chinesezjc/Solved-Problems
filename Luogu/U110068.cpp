//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int p,q,cntp,cntq,sp[6001],sq[6001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>p>>q;
	for(int i=1;i<=p;++i)
	{
		if(p%i)
		{
			continue;
		}
		for(int j=1;j<=q;++j)
		{
			if(q%j)
			{
				continue;
			}
			cout<<i<<' '<<j<<endl;
		}
	}
	return 0;
}

