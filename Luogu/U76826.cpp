#include<cstdio>
#define max(a,b) a<b?b:a
using namespace std;
int n,sum[101][101],ans,Max;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&sum[i][j]);
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			Max=0;
			for(int k=1;k<=n;++k)
			{
				if(Max<0)
				{
					Max=0;
				}
				Max+=sum[k][j]-sum[k][i];
				ans=max(ans,Max);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
