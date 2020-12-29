//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int now,l[1000001],x,y,ans,n;
void read(int &X)
{
	X=0;
	char c=getchar();
	while('0'>c||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		X=(X<<3)+(X<<1)+(c^'0');
		c=getchar();
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		now+=l[i];
		if(x==1)
		{
			read(x);
			now+=x;
			continue;
		}
		if(x==2)
		{
			read(x);
			if(now<x)
			{
				++ans;
			}
			else
			{
				now-=x;
			}
			continue;
		}
		if(x==3)
		{
			read(x);
			read(y);
			l[y]+=x;
			now-=x;
		}
	}
	cout<<ans;
	return 0;
}

