#include<cstdio>
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
int n,num[101],sum,ans;
signed main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(num[i]);
		sum+=num[i];
	}
	sum/=n;
	for(int i=1;i<n;++i)
	{
		if(num[i]!=sum)
		{
			++ans;
			num[i+1]-=sum-num[i];
		}
	}
	printf("%lld",ans);
	return 0;
}

