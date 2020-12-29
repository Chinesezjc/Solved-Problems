//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,p,a[1000001],b[1000001],sum;
struct small_l{
	int b,s;
	small_l operator+=(const int x)
	{
		s+=x;
		b+=s/p;
		s%=p;
		return *this;
	}
	bool operator<(const small_l x)const
	{
		return b==x.b?s<x.s:b<x.b;
	}
}c[1000001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>p;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	b[0]=-INF;
	for(int i=1;i<=n;++i)
	{
		b[i]=max(b[i-1],a[i]);
		if(a[i]>0)
		{
			sum=0;
			while(i<=n)
			{
				if(sum+a[i]>0)
				{
					sum+=a[i];
				}
				else
				{
					sum=0;
				}
				b[i]=max(b[i-1],sum);
				++i;
			}
		}
	}
	c[1]+=b[1];
	c[2]=c[1];
	c[2]+=b[1];
	for(int i=3;i<=n;++i)
	{
		c[i]=c[i-1];
		if(b[i-1]>0)
		{
			c[i]+=b[i-1];
		}
	}
	if(c[1]<c[n])
	{
		cout<<c[n].s;
	}
	else
	{
		cout<<c[1].s;
	}
	return 0;
}

