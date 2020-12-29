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
int n,m,num,que[100],ans;
bool flag;
signed main()
{
	rd(m);
	rd(n);
	fill(que,que+m,-1);
	for(int i=1;i<=n;++i)
	{
		rd(num);
		flag=true;
		for(int j=0;j<m;++j)
		{
			if(que[j]==num)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			que[(++ans)%m]=num;
		}
	}
	printf("%lld",ans);
	return 0;
}


