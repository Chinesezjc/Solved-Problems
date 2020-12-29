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
int n;
struct student{
	int num,sum,Chinese,math,English;
	inline void init(const int &i)
	{
		num=i;
		rd(Chinese);
		rd(math);
		rd(English);
		sum=Chinese+math+English;
	}
}a[301];
inline bool cmp(const student &A,const student &B)
{
	return A.sum==B.sum?(A.Chinese==B.Chinese?A.num<B.num:A.Chinese>B.Chinese):A.sum>B.sum;
}
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		a[i].init(i);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;++i)
	{
		printf("%lld %lld\n",a[i].num,a[i].sum);
	}
	return 0;
}

