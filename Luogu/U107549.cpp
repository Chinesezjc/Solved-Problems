//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int x,y;
int f(int n)
{
	int tmp=0;
	for(int i=1;i<=n;i<<=1)
	{
		tmp+=i*(n/i-(n/(i<<1)));
	}
	return tmp;
}
string _(int tmp)
{
	if(tmp==0)
	{
		return "";
	}
	if(tmp&1)
	{
		return _(tmp>>1)+'1';
	}
	else
	{
		return _(tmp>>1)+'0';
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>x>>y;
	cout<<f(y)-f(x-1);
	return 0;
}

