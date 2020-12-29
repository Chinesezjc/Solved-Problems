//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a,now,md;
int n,k,l,r,mid;
bool can[200001],flag;
bool work(int s)
{
	now=a.substr(0,k);
	if(s>0)
	{
		++now[k-s];
		for(int j=k-s;now[j]>'9';--j)
		{
			now[j]-=10;
			++now[j-1];
		}
	}
	for(int i=0;i<n;++i)
	{
		if(now[i%k]<a[i])
		{
			return false;
		}
		if(now[i%k]>a[i])
		{
			return true;
		}
	}
	return true;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>a;
	cout<<n<<endl;
	l=0;
	r=k;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(work(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	work(mid=(l+r)>>1);
	for(int i=0;i<n;++i)
	{
		cout<<now[i%k];
	}
	return 0;
}

