//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dl[1081],x[1081],y[1081],R[1081],n,l,r;
bool went[1081];
int square(int a)
{
	return a*a;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i]>>R[i];
		if(x[i]==0&&y[i]==0)
		{
			dl[++r]=i;
			went[i]=true;
		}
	}
	while(l<r)
	{
		++l;
		for(int i=1;i<=n;++i)
		{
			if(went[i])
			{
				continue;
			}
			if(square(x[i]-x[dl[l]])+square(y[i]-y[dl[l]])<=square(R[i]+R[dl[l]]))
			{
				dl[++r]=i;
				went[i]=true;
			}
		}
	}
	cout<<x[dl[r]]<<' '<<y[dl[r]]<<endl;
	return 0;
}

