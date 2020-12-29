//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int x,y,n,p,tmp;
void exgcd(int a,int b)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	swap(x,y);
	y=y-a/b*x;
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
		exgcd(i,p);
		write((x%p+p)%p);
		putchar('\n');
	}
	return 0;
}

