//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define Ef 0.6180339887498949
using namespace std;
int n,a[30001],ansl,ansr;
double best=INF;
void find(double now,int d)
{
	int l=1,r=d-1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(a[mid]<now)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	if(abs(a[l]-now)<abs(a[r]-now))
	{
		if(abs(a[l]-now)<best)
		{
			best=abs(a[l]-now);
			ansl=l;
			ansr=d;
		}
	}
	else
	{
		if(abs(a[r]-now)<best)
		{
			best=abs(a[r]-now);
			ansl=r;
			ansr=d;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		find(a[i]*Ef,i);
	}
	cout<<a[ansl]<<endl<<a[ansr];
	return 0;
}

