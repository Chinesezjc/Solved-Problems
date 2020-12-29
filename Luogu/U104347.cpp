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
int n,ans,i;
int l(int N)
{
	return (N%MOD)*((N+1)%MOD)%MOD*499122177%MOD;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	i=1;
	while(i*i<=n)
	{
		ans=(ans+(l(n/i)-l(n/(i+1)))*i+n/i*i)%MOD;
		++i;
	}
	--i;
	if(n/i==i)
	{
		ans-=n/i*i;
	}
	if(ans<0)
	{
		ans%=MOD;
		ans+=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
