//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p,k,a[5000002],qian[5000002],hou[5000002],x,y,now,ans;
void read(int &X)
{
	X=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		X=(X<<3)+(X<<1)+(c^'0');
		c=getchar();
	}
}
void exgcd(int a,int b)
{
	if(!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b);
	swap(x,y);
	y=y-a/b*x;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	read(n);
	read(p);
	read(k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	qian[0]=1;
	for(int i=1;i<=n;++i)
	{
		qian[i]=qian[i-1]*a[i]%p;
	}
	hou[n+1]=1;
	for(int i=n;i;--i)
	{
		hou[i]=hou[i+1]*a[i]%p;
	}
	now=1;
	for(int i=1;i<=n;++i)
	{
		now*=k;
		now%=p;
		ans+=now*qian[i-1]%p*hou[i+1]%p;
		ans%=p;
	}
	exgcd(hou[1],p);
	x=(x%p+p)%p;
	printf("%lld",ans*x%p);
	return 0;
}

