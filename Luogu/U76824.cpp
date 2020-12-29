#include<cstdio>
using namespace std;
long long dp[40][2000],n,max;
int main()
{
	scanf("%lld",&n);
	max=(1+n)*n/2;
	dp[0][1000]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=-max;j<=max;++j)
		{
			dp[i][j+1000]=dp[i-1][j-i+1000]+dp[i-1][j+i+1000];
		}
	}
	printf("%lld",dp[n][1000]/2);
	return 0;
}
