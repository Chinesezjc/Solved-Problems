//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
double l,r,a[14],mid1,mid2;
bool l_mid1,mid1_mid2,mid2_r;
double f(double x)
{
	double S=0;
	for(int i=n;i>=0;--i)
	{
		S=S*x+a[i];
	}
	return S;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>l>>r;
	for(int i=n;i>=0;--i)
	{
		cin>>a[i];
	}
	while(l+0.0000001<r)
	{
		mid2=mid1=(r-l)*0.618;
		mid1=r-mid1;
		mid2=l+mid2;
		if(f(mid1)<f(mid2))
		{
			l=mid1;
		}
		else
		{
			r=mid2;
		}
	}
	cout<<fixed<<setprecision(5)<<l<<endl;
	return 0;
}

