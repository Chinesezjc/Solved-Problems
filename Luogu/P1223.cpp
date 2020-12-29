#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
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
	return ddd*=xxx;
}
inline char rd(char &ddd)
{
	char tmp=getchar();
	while(tmp==' '||tmp=='\n')
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	return ddd=tmp;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
struct person{
	int s,p;
	inline void init(const int &i)
	{
		p=i;
		rd(s);
	}
}p[1001];
int n,ans;
inline bool cmp(const person &A,const person &B)
{
	return A.s==B.s?A.p<B.p:A.s<B.s;
}
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		p[i].init(i);
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",p[i].p);
		ans+=p[i].s*(n-i);
	}
	printf("\n%.2lf",ans*1.0/n);
	return 0;
}

