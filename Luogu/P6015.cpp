//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,sum[1000001],k,x,y,ans[1000001],cnt;
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
bool check(int i)
{
	while(sum[y]-sum[x]<=i)
	{
		++y;
	}
	--y;
	return sum[x]>sum[y]-sum[x];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x);
		sum[i]=sum[i-1]+x;
	}
	read(k);
	if(n==1)
	{
		cout<<k-sum[1]+1<<endl;
		for(int i=sum[1];i<=k;++i)
		{
			cout<<i<<' ';
		}
		return 0;
	}
	x=0;
	for(int i=1;i<=k;++i)
	{
		while(sum[x]<=i&&(!check(i)))
		{
			++x;
		}
		if(sum[x]>i)
		{
			--x;
		}
		else
		{
			ans[++cnt]=i;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}

