#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct C{
	int h,a,c;
}c[401];
int n,ans;
bool dp[40001];
bool cmp(const C &A,const C &B)
{
	return A.a<B.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&c[i].h,&c[i].a,&c[i].c);
	}
	sort(c+1,c+1+n,cmp);
	dp[0]=true;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=c[i].c;++j)
		{
			for(int k=c[i].a;k>=c[i].h;--k)
			{
				dp[k]=max(dp[k],dp[k-c[i].h]);
				if(dp[k])
				{
					ans=max(k,ans);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
