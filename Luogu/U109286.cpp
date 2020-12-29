//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[20001],b[20001],c[20001],ans,l,r,mid;
int get(int now)
{
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>now)
		{
			continue;
		}
		tmp+=(min(now,b[i])-a[i])/c[i]+1;
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	l=1;
	r=INF;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(get(mid)&1)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l==INF)
	{
		cout<<"Bonus Clear!"<<endl;
		return 0;
	}
	cout<<l<<endl<<get(l)-get(l-1);
	return 0;
}

