#include<cstdio>
using namespace std;
inline void rd(long long &ddd)
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
struct carpet{
	long long x,y,a,b;
}a[10001];
long long n,x,y;
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(a[i].x);
		rd(a[i].y);
		rd(a[i].a);
		rd(a[i].b);
	}
	rd(x);
	rd(y);
	for(int i=n;i>0;--i)
	{
		if(a[i].x<=x&&x<=a[i].x+a[i].a&&a[i].y<=y&&y<=a[i].y+a[i].b)
		{
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}


