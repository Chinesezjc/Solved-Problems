//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[100001],now,ans;
struct l{
	int p,now;
	bool operator < (const l &tmp)const
	{
		return now==tmp.now?p<tmp.p:now<tmp.now;
	}
}sum[100001];
int find()
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(sum[mid].now<now)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return sum[l].p;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			a[i]=-1;
		}
		sum[i].p=i;
		sum[i].now=sum[i-1].now+a[i];
	}
	sort(sum+1,sum+1+n);
	for(int i=1;i<=n;++i)
	{
		now+=a[i];
		if(now==0)
		{
			ans=i;
		}
		ans=max(ans,i-find());
	}
	cout<<ans<<endl;
	return 0;
}

