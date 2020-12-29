//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int f[3000001],fact[3000001],n,p,x,y;
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
	fact[0]=1;
	for(int i=1;i<=n;++i)
	{
		fact[i]=fact[i-1]*i%p;
	}
	exgcd(fact[n],p);
	f[n]=(x%p+p)%p;
	for(int i=n-1;i>0;--i)
	{
		f[i]=f[i+1]*(i+1)%p;
	}
	for(int i=1;i<=n;++i)
	{
		write(f[i]*fact[i-1]%p);
		putchar('\n');
	}
	return 0;
}

