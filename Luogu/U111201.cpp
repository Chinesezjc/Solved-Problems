//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int fa[151],f[301],t[301],now,n,m,ans;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct A{
	int x,y;
	bool operator < (const A &TMP)const
	{
		return x==TMP.x?y<TMP.y:x<TMP.x;
	}
}A[301];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>f[i]>>t[i];
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			fa[j]=j;
		}
		now=n;
		for(int j=1;j<i;++j)
		{
			if(find(f[j])!=find(t[j]))
			{
				--now;
				fa[find(f[j])]=find(t[j]);
			}
		}
		for(int j=i+1;j<=m;++j)
		{
			if(find(f[j])!=find(t[j]))
			{
				--now;
				fa[find(f[j])]=find(t[j]);
			}
		}
		if(now>1)
		{
			++ans;
			A[ans].x=f[i];
			A[ans].y=t[i];
			if(A[ans].x>A[ans].y)
			{
				swap(A[ans].x,A[ans].y);
			}
		}
	}
	sort(A+1,A+ans+1);
	for(int i=1;i<=ans;++i)
	{
		cout<<A[i].x<<' '<<A[i].y<<endl;
	}
	return 0;
}

