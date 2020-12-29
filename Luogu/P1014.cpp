#include<cstdio>
#include<cmath>
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
long long n,m;
int main()
{
	rd(n);
	m=sqrt(n<<1);
	for(long long i=m-1;i<=m+1;++i)
	{
		if(((i+1)*i)>>1<n&&n<=((i+2)*(i+1))>>1)
		{
			m=i;
			break;
		}
	}
	if(m%2)
	{
		printf("%lld/%lld",n-(((m+1)*m)>>1),m+2-(n-(((m+1)*m)>>1)));
	}
	else
	{
		printf("%lld/%lld",m+2-(n-(((m+1)*m)>>1)),n-(((m+1)*m)>>1));
	}
	return 0;
}

