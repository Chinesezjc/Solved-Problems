//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 998244353
using namespace std;
int n,m,k,ans,d[200001],p[200001];
int power(int a,int b,int c)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=(tmp*a)%c;
		}
		a=(a*a)%c;
		b>>=1;
	}
	return tmp;
}
int C(int n,int m)
{
	return d[n]*p[n-m]%MOD*p[m]%MOD;
}
int s(int n,int m)
{
	return m*power(m-1,n-1,MOD)%MOD;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	d[0]=1;
	p[0]=1;
	for(int i=1;i<=n;++i)
	{
		d[i]=d[i-1]*i%MOD;
		p[i]=power(d[i],MOD-2,MOD);
	}
	for(int i=0;i<=k;++i)
	{
		ans=(ans+s(n-i,m)*C(n-1,n-i-1)%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}

