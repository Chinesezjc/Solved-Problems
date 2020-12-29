//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
struct Thing{
	int w,p,l;
}t[500001],best[11];
double bestw=INF;
bool cmp(const Thing &A,const Thing &B)
{
	return A.p==B.p?A.w<B.w:A.p<B.p;
}
void dfs(int now)
{
	if(now>n)
	{
		double pnow[11]={1},k,b=0;
		for(int i=1;i<=n;++i)
		{
			pnow[i]=pnow[i-1]*t[i].p/10000.0;
		}
		for(int i=1;i<=n;++i)
		{
			b+=pnow[i-1]*t[i].w;
		}
		k=-pnow[n];
//		kx+b=0
//		x=-b/k
		if(-b/k<bestw)
		{
			bestw=-b/k;
			for(int i=1;i<=n;++i)
			{
				best[i]=t[i];
			}
		}
		return;
	}
	for(int i=now;i<=n;++i)
	{
		swap(t[i],t[now]);
		dfs(now+1);
		swap(t[i],t[now]);
	}
}
signed work_n10()
{
	dfs(1);
	for(int i=1;i<=n;++i)
	{
		cout<<best[i].l<<' ';
	}
	return 0;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i].w;
		t[i].l=i;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>t[i].p;
		if(t[i].p==0)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	if(n<=10)
	{
		work_n10();
		return 0;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		cout<<t[i].l<<' ';
	}
	return 0;
}

