//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int l,r;
int f(int now)
{
	int k=2,ans=2,i=1,j=1,l=1;
	while(k+(l<<i)<=now)
	{
		k+=l<<i;
		ans^=((l<<i)-1)<<1;
		++i;
	}
	++i;
	if(k==now)
	{
		return ans;
	}
	++k;
	++i;
	ans^=((l<<i)-1)^((l<<(i-1))-2);
	if(k==now)
	{
		return ans;
	}
	while(k+(l<<j)<now)
	{
		k+=l<<j;
		++j;
	}
	++j;
	j=i-1-j;
	if((now-k)&1)
	{
		ans^=((l<<i)-1)^(((l<<j)-1)<<1);
	}
	return ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>l>>r;
	cout<<(f(l-1)^f(r));
	return 0;
}
