//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int p,t,a[100001];
int power(int a,int b)
{
	int ans=1;
	a%=p;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=p;
		}
		a*=a;
		a%=p;
		b>>=1;
	}
	return ans;
}
int C(int m,int n)
{
	if(m==0||m==n)
	{
		return 1;
	}
	if(m>n)
	{
		return 0;
	}
	if(n<p)
	{
		return a[n]%p*power(a[m],p-2)%p*power(a[n-m],p-2)%p;
	}
	return C(m/p,n/p)%p*C(m%p,n%p)%p;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>t;
	a[0]=1;
	while(t)
	{
		--t;
		cin>>n>>m>>p;
		for(int i=1;i<=p;++i)
		{
			a[i]=a[i-1]*i%p;
		}
		cout<<C(m,n+m)<<endl;
	}
	return 0;
}

