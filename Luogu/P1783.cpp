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
struct EDGE{
	int f,t;
	double v;
	bool operator < (const EDGE &tmp)const
	{
		return v<tmp.v;
	}
}e[1000001];
int n,m,x[802],y[802],fa[802],cnt;
double ans;
int w(int tmp)
{
	return tmp*tmp;
}
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>x[i]>>y[i];
		fa[i]=i;
	}
	fa[m+1]=m+1;
	for(int i=1;i<=m;++i)
	{
		++cnt;
		e[cnt].f=0;
		e[cnt].t=i;
		e[cnt].v=x[i];
	}
	for(int i=1;i<=m;++i)
	{
		++cnt;
		e[cnt].f=m+1;
		e[cnt].t=i;
		e[cnt].v=n-x[i];
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			++cnt;
			e[cnt].f=i;
			e[cnt].t=j;
			e[cnt].v=sqrt(w(x[i]-x[j])+w(y[i]-y[j]))/2;
		}
	}
	sort(e+1,e+1+cnt);
	for(int i=1;find(0)!=find(m+1);++i)
	{
		if(find(e[i].f)!=find(e[i].t))
		{
			ans=e[i].v;
			fa[find(e[i].f)]=find(e[i].t);
		}
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}

