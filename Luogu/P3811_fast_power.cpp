//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p;
int fast_power(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=p;
		}
		a*=a;
		a%=p;
		b>>=1;
	}
	return ans;
}
void write(int now)
{
	if(now>9)
	{
		write(now/10);
	}
	putchar(now%10^48);
}
signed main()
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;++i)
	{
		write(fast_power(i,p-2,p));
		putchar('\n');
	}
	return 0;
}

