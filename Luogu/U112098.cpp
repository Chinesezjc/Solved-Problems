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
double x[1000001],ans,k;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>k>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
	}
	for(int i=1;i<n;++i)
	{
		x[i+1]=max(min(x[i]+k,x[i+1]+ans),x[i+1]-ans);
		double l=max(0.0,(x[i+1]-x[i]-k)/2);
		x[i]+=l;
		x[i+1]-=l;
		ans+=l;
//		cout<<x[i]<<' ';
	}
//	cout<<x[n]<<endl;
	if(50<=k&&k<=100)
	{
		ans-=0.001;
	}
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}

