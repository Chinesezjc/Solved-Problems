//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,l,ansa,ansb;
double s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>l;
	s=1.0*a/b;
	ansa=l;
	ansb=1;
	for(int i=1,j=i/s;i<=l&&j<=l;++i,j=i/s)
	{
		if(i*ansb<ansa*j)
		{
			ansa=i;
			ansb=j;
		}
	}
	cout<<ansa<<' '<<ansb;
	return 0;
}
