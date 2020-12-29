#include<cstdio>
#define min(a,b) a<b?a:b
using namespace std;
int n,f,t,dp[201],num[201];
bool flag;
int main()
{
	scanf("%d%d%d",&n,&f,&t);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num[i]);
		dp[i]=-1;
	}
	dp[f]=0;
	do
	{
		flag=false;
		for(int i=1;i<=n;++i)
		{
			if(dp[i]==-1)
			{
				continue;
			}
			if(i+num[i]<=n&&(dp[i+num[i]]>dp[i]+1||dp[i+num[i]]==-1))
			{
				flag=true;
				dp[i+num[i]]=dp[i]+1;
			}
			if(i-num[i]>=1&&(dp[i-num[i]]>dp[i]+1||dp[i-num[i]]==-1))
			{
				flag=true;
				dp[i-num[i]]=dp[i]+1;
			}
		}
	}
	while(flag);
	printf("%d",dp[t]);
	return 0;
}
