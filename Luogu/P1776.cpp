#include<cstdio>
#include<iostream>
using namespace std;
int n,m,dp[40001],x,y,z,k;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		k=1;
		--z;
		while(z>0)
		{
			for(int j=m;j>=y*k;--j)
			{
				dp[j]=max(dp[j],dp[j-y*k]+x*k);
			}
			k<<=1;
			z-=k;
		}
		z+=k;
		for(int j=m;j>=y*z;--j)
		{
			dp[j]=max(dp[j],dp[j-y*z]+x*z);
		}
	}
	printf("%d",dp[m]);
	return 0;
}
