#include<cstdio>
#define max(a,b) a<b?b:a
using namespace std;
int n,iv,k,v[101],dp[101][301],ans;
int main()
{
	scanf("%d%d%d",&n,&iv,&k);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",&v[i]);
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<=200;++j)
		{
			dp[i][j]=-0x7fffffff;
		}
	}
	if(v[n]<=iv&&iv<=v[n]+k)
	{
		dp[n][iv]=iv;
	}
	for(int i=n-1;i>1;--i)
	{
		for(int j=v[i];j<=v[i]+k;++j)
		{
			dp[i][j]=max(dp[i][j],dp[i+1][j-1]+j);
			dp[i][j]=max(dp[i][j],dp[i+1][j]+j);
			dp[i][j]=max(dp[i][j],dp[i+1][j+1]+j);
		}
	}
	for(int i=v[2];i<=v[2]+k;++i)
	{
		ans=max(ans,dp[2][i]);
	}
	if(ans)
	{
		printf("%.2lf",ans/(n-1.0));
	}
	else
	{
		puts("YI DING YAO JIAN CHI ZUO URAL");
	}
	return 0;
}
