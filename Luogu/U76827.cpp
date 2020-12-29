#include<cstdio>
#define max(a,b) (a<b?b:a)
using namespace std;
int n,m,num[101][101],dp[101][101],ans=-0x3fffffff;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=-0x3fffffff;
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&num[i][j]);
			dp[i][j]=-0x3fffffff;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			for(int k=j-1;k>=0;--k)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][k]+num[i][j]);
			}
		}
	}
	for(int i=n;i<=m;++i)
	{
		ans=max(ans,dp[n][i]);
	}
	printf("%d",ans);
	return 0;
}
