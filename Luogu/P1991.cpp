#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	int xxx=1;
	ddd=0;
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd*=xxx;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
inline int sqr(const int &A)
{
	return A*A;
}
int n,m,x[501],y[501],fa[501],cnt;
double ans;
struct WAY{
	int f,t;
	double v;
}way[250001];
inline int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
inline void add(int f,int t)
{
	++cnt;
	way[cnt].f=f;
	way[cnt].t=t;
	way[cnt].v=sqrt(sqr(x[f]-x[t])+sqr(y[f]-y[t]));
}
inline bool cmp(const WAY &A,const WAY &B)
{
	return A.v>B.v;
}
signed main()
{
	rd(m);
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(x[i]);
		rd(y[i]);
		fa[i]=i;
		for(int j=1;j<i;++j)
		{
			add(i,j);
		}
	}
	sort(way+1,way+1+cnt,cmp);
	while(n>m)
	{
		if(find(way[cnt].f)!=find(way[cnt].t))
		{
			fa[find(way[cnt].f)]=find(way[cnt].t);
			ans=way[cnt].v;
			--n;
		}
		--cnt;
	}
	printf("%.2lf",ans);
	return 0;
}

