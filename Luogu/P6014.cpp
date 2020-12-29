//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x,s[21],sum;
bool flag;
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
		++s[x];
		sum+=x;
	}
	sum%=10;
	if(sum==0)
	{
		sum=10;
	}
	for(int i=1;i<=10;++i)
	{
		--s[i];
		if(sum-i>0)
		{
			--s[sum-i];
			if(s[i]>=0&&s[sum-i]>=0)
			{
				flag=true;
				break;
			}
			++s[sum-i];
		}
		--s[sum+10-i];
		if(s[i]>=0&&s[sum+10-i]>=0)
		{
			flag=true;
			break;
		}
		++s[sum+10-i];
		++s[i];
	}
	if(flag)
	{
		cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

