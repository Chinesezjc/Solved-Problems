//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[100001],b[100001],t,n,m,fa[100001],sum[100001],cnt,head[100001];
bool T2;
struct L{
	int t,u,v;
}l[100001];
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
struct EDGE{
	int n,t;
}e[200001];
void add(int F,int T)
{
	++cnt;
	e[cnt].n=head[F];
	e[cnt].t=T;
	head[F]=cnt;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			fa[i]=i;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>b[i];
		}
		T2=true;
		for(int i=1;i<=m;++i)
		{
			cin>>l[i].t>>l[i].u>>l[i].v;
			if(l[i].u>l[i].v)
			{
				swap(l[i].u,l[i].v);
			}
			if(l[i].t==2)
			{
				T2=false;
			}
		}
		if(n==2)
		{
			if((a[1]+a[2]-b[1]-b[2])&1)
			{
				cout<<"NO"<<endl;
				continue;
			}
			bool t1=false,t2=false;
			for(int i=1;i<=m;++i)
			{
				if(l[i].t==1)
				{
					t1=true;
				}
				if(l[i].t==2)
				{
					t2=true;
				}
			}
			if(a[1]+a[2]==b[1]+b[2])
			{
				t1=true;
			}
			if(a[1]-a[2]==b[1]-b[2])
			{
				t2=true;
			}
			if(t1&&t2)
			{
				cout<<"YES"<<endl;
				continue;
			}
			else
			{
				cout<<"NO"<<endl;
				continue;
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(l[i].t==2)
			{
				fa[find(l[i].u)]=find(l[i].v);
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(l[i].t==1)
			{
				add(l[i].u,l[i].v);
				add(l[i].v,l[i].u);
			}
		}
		for(int i=1;i<=n;++i)
		{
			sum[find(i)]+=a[i]-b[i];
		}
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(sum[i])
			{
				sum[i]=0;
				flag=false;
			}
		}
		if(flag)
		{
			cout<<"YES"<<endl;
			continue;
		}
		else
		{
			cout<<"NO"<<endl;
			continue;
		}
	}
	return 0;
}

