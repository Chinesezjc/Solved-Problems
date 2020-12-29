//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,k,x,y,z,cnt,head[500001],in[500001],out[500001],v[500001],que[500001],l,r;
struct Edge{
	int n,t,v;
}e[500001];
void add(int a,int b,int c)
{
	++cnt;
	++out[a];
	++in[b];
	e[cnt].n=head[a];
	e[cnt].t=b;
	e[cnt].v=c;
	head[a]=cnt;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y>>z;
		add(x,y,z);
	}
	que[++r]=1;
	v[1]=k;
	while(l<r)
	{
		++l;
		for(int i=head[que[l]];i;i=e[i].n)
		{
			v[e[i].t]+=max(0ll,v[que[l]]/out[que[l]]-e[i].v);
			--in[e[i].t];
			if(in[e[i].t]==0)
			{
				que[++r]=e[i].t;
			}
		}
	}
	cout<<v[n];
	return 0;
}

