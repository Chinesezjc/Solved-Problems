#include<cstdio>
#include<algorithm>
using namespace std;
int num[100001],n;
bool use[100001];
struct ll{
	int v,t;
}sor[100001];
bool cmp(const ll &A,const ll &B)
{
	return A.v>B.v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num[i]);
		sor[i].v=num[i];
		sor[i].t=i;
	}
	sort(sor+1,sor+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		if(use[sor[i].t])
		{
			continue;
		}
		for(int j=sor[i].t+1;j<=n;++j)
		{
			if(!use[j])
			{
				use[sor[i].t]=true;
				use[sor[i].t+1]=true;
				printf("%d %d ",sor[i].v,num[j]);
				break;
			}
		}
	}
	return 0;
}
