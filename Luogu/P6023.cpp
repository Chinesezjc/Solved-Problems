//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,k,head[100001],cnt,ans,now,x,y;
struct good{
	int b,n;
}G[100001];
void add(int d,int b)
{
	++cnt;
	G[cnt].b=b;
	G[cnt].n=head[d];
	head[d]=cnt;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i)
	{
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=m;++i)
	{
		now=0;
		for(int j=head[i];j;j=G[j].n)
		{
			now+=n-G[j].b;
		}
		ans=max(now,ans);
	}
	cout<<ans;
	return 0;
}

