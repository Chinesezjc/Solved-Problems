//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 998244353
using namespace std;
signed cnt,n,p[664580],phi[10000001],ans;
void Euler_screen()
{
	for(int i=2;i<=n;++i)
	{
		if(phi[i]==0)
		{
			p[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*p[j]<=n;++j)
		{
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j]%MOD;
				break;
			}
			else
			{
				phi[i*p[j]]=phi[i]*(p[j]-1)%MOD;
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	phi[1]=1;
	Euler_screen();
	for(int i=1;i<=n;++i)
	{
		ans=(ans+phi[i])%MOD;
	}
	cout<<ans;
	return 0;
}

