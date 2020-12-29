//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,l,r,cnt,x[100001],y[100001];
struct A{
	int a,b;
	bool operator < (const A tmp)const
	{
		return a<tmp.a;
	}
}a[100001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+1+n);
	l=r=-INF;
	for(int i=1;i<=n;++i)
	{
		if(a[i].a<=r)
		{
			r=max(a[i].b,r);
		}
		else
		{
			++cnt;
			x[cnt]=l;
			y[cnt]=r;
			l=a[i].a;
			r=a[i].b;
		}
	}
	++cnt;
	x[cnt]=l;
	y[cnt]=r;
	x[cnt+1]=INF;
	for(int i=2;i<=cnt;++i)
	{
		if(x[i]<y[i]&&y[i]<x[i+1])
		{
			cout<<x[i]<<' '<<y[i]<<endl;
			continue;
		}
		return cnt;
	}
	return 0;
}

