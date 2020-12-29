//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,X,now,times;
void read(int &x)
{
	x=0;
	int l=1;
	char c=getchar();
	while(('0'>c||c>'9')&&c!='-')
	{
		c=getchar();
	}
	if(c=='-')
	{
		l=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	x*=l;
}
signed main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(X);
		if(X!=now)
		{
			if(times==0)
			{
				now=X;
				++times;
			}
			else
			{
				--times;
			}
		}
		else
		{
			++times;
		}
	}
	cout<<now;
	return 0;
}

