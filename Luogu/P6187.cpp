//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,k,a[200001],l,ans[200001],sum;
signed main()
{
	std::ios::sync_with_stdio(false);
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		ans[0]+=a[i]*a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;++i)
	{
		sum+=a[i-2]*a[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>k;
		if(ans[k])
		{
			cout<<ans[k]<<endl;
			continue;
		}
		l=n/__gcd(n,k);
		ans[k]=sum;
		for(int i=l;i<=n;i+=l)
		{
			ans[k]+=a[i-l+1]*a[i-l+2]+a[i-1]*a[i];
		}
		for(int i=l;i<n;i+=l)
		{
			ans[k]-=a[i+1]*a[i-1]+a[i+2]*a[i];
		}
		cout<<ans[k]<<endl;
	}
	return 0;
}

