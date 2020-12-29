//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p,ans[3000001];
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
	ans[1]=1;
	putchar('1');
	putchar('\n');
	for(int i=2;i<=n;++i)
	{
		write(ans[i]=((p-p/i)*ans[p%i])%p);
		putchar('\n');
	}
	return 0;
}

