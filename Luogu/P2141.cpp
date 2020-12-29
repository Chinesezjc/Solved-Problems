#include<cstdio>
using namespace std;
bool can[20001];
int has[10001],n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&ans);
		++has[ans];
	}
	for(int i=1;i<=10000;++i)
	{
		if(!has[i])
		{
			continue;
		}
		--has[i];
		for(int j=i;j<=10000;++j)
		{
			if(!has[j])
			{
				continue;
			}
			can[i+j]=true;
		}
		++has[i];
	}
	ans=0;
	for(int i=1;i<=10000;++i)
	{
		if(can[i])
		{
			ans+=has[i];
		}
	}
	printf("%d",ans);
}
