#include<cstdio>
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
int min(int a,int b)
{
	return a<b?a:b;
}
int n,m,t,ans,l;
struct MAP{
	int x,y,h;
}map[401];
bool cmp(const MAP &A,const MAP &B)
{
	return A.h>B.h;
}
signed main()
{
	rd(n);
	rd(m);
	rd(t);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			rd(map[++l].h);
			map[l].x=i;
			map[l].y=j;
		}
	}
	sort(map+1,map+1+n*m,cmp);
	l=1;
	if(t>=(map[l].x<<1)+1)
	{
		ans+=map[l].h;
		t-=map[l].x+1;
	}
	else
	{
		puts("0");
		return 0;
	}
	while(true)
	{
		++l;
		if(t>=abs(map[l-1].x-map[l].x)+abs(map[l-1].y-map[l].y)+map[l].x+1)
		{
			ans+=map[l].h;
			t-=abs(map[l-1].x-map[l].x)+abs(map[l-1].y-map[l].y)+1;
		}
		else
		{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}

