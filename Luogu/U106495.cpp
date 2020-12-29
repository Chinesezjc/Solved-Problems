//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int sum,l,r,t;
void read(int &tmp)
{
	tmp=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+(c^'0');
		c=getchar();
	}
}
void write(int tmp)
{
	if(tmp==0)
	{
		return;
	}
	write(tmp/10);
	putchar(tmp%10+'0');
}
signed main()
{
	read(t);
	while(t)
	{
		--t;
		read(l);
		read(r);
		sum=r*r%1000000;
		if(sum==0)
		{
			puts("0");
		}
		else
		{
			write(sum);
			puts("");
		}
	}
	return 0;
}

