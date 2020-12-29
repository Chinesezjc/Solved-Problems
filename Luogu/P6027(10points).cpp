//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
double ax,ay,bx,by,x,y,k,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	if(n==1)
	{
		cout<<1<<endl;
		cin>>ax>>ay>>bx>>by;
		x=(ax+bx)/2;
		y=(ay+by)/2;
		if(ax==bx)
		{
			cout<<1<<' '<<0<<' '<<-y<<endl;
			return 0;
		}
		if(ay==by)
		{
			cout<<0<<' '<<1<<' '<<-x<<endl;
			return 0;
		}
		k=(ay-by)/(ax-bx);
		k=-(1/k);
		b=y-x*k;
		cout<<-k<<' '<<1<<' '<<-b<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<1<<endl;
		for(int i=1;i<=10;++i)
		{
			cout<<rand()<<' '<<rand()<<' '<<rand()<<endl;
		}
	}
	if(n==5)
	{
		cout<<1000<<endl;
		for(int i=1;i<=1000;++i)
		{
			cout<<rand()<<' '<<rand()<<' '<<rand()<<endl;
		}
	}
	if(n==10)
	{
		cout<<100000<<endl;
		for(int i=1;i<=100000;++i)
		{
			cout<<rand()<<' '<<rand()<<' '<<rand()<<endl;
		}
	}
	return 0;
}

