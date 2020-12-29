//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
#define pi 3.14159265358979323
using namespace std;
int n;
double r,x[101],y[101],ans;
double l(double a)
{
	return a*a;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>r;
	for(int i=0;i<n;++i)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;++i)
	{
		ans+=sqrt(l(x[i]-x[(i+1)%n])+l(y[i]-y[(i+1)%n]));
	}
	cout<<fixed<<setprecision(2)<<ans+2*r*pi;
	return 0;
}

