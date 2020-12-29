//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,q,a[100001],b[100001],X,Y,Z,suma,sumb,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		suma+=a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
		sumb+=b[i];
	}
	for(int i=1;i<=n;++i)
	{
		ans+=a[i]*b[i]*n;
	}
	ans-=suma*sumb;
	for(int i=1;i<=q;++i)
	{
		cin>>X>>Y>>Z;
		if(X==1)
		{
			ans-=a[Y]*b[Y]*n;
			ans+=a[Y]*sumb;
			suma-=a[Y];
			a[Y]=Z;
			suma+=a[Y];
			ans-=a[Y]*sumb;
			ans+=a[Y]*b[Y]*n;
		}
		if(X==2)
		{
			ans-=b[Y]*a[Y]*n;
			ans+=b[Y]*suma;
			sumb-=b[Y];
			b[Y]=Z;
			sumb+=b[Y];
			ans-=b[Y]*suma;
			ans+=b[Y]*a[Y]*n;
		}
		cout<<ans<<endl;
	}
	return 0;
}

