//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[11],b[11],M[11],m=1,x,y,ans,k;
void exgcd(int A,int B)
{
	if(B==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(B,A%B);
	int tmp=x;
	x=y;
	y=tmp-A/B*y;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>k;
	for(int i=1;i<=k;++i)
	{
		cin>>a[i]>>b[i];
		m*=a[i];
	}
	for(int i=1;i<=k;++i)
	{
		M[i]=m/a[i];
	}
	for(int i=1;i<=k;++i)
	{
		exgcd(M[i],a[i]);
		x=(x+a[i])%a[i];
		ans+=x*M[i]*b[i];
		ans%=m;
	}
	cout<<ans;
	return 0;
}

