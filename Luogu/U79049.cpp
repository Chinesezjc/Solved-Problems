#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
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
	ddd*=xxx;
}
int n,m,x[2001],y[2001],fa[2001],cnt;
double ans;
struct WAY{
	int f,t;
	double v;
}way[4000001];
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
long long sqr(long long A)
{
	return A*A;
}
void add(int f,int t)
{
	++cnt;
	way[cnt].f=f;
	way[cnt].t=t;
	way[cnt].v=sqrt(sqr(x[f]-x[t])+sqr(y[f]-y[t]));
}
bool cmp(const WAY &A,const WAY &B)
{
	return A.v>B.v;
}
signed main()
{
	rd(n);
	rd(m);
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
		--n;
		while(find(way[cnt].f)==find(way[cnt].t))
		{
			--cnt;
		}
		fa[find(way[cnt].f)]=find(way[cnt].t);
		ans=way[cnt].v;
	}
	printf("%.2lf",ans);
	return 0;
}

