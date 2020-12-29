#include<cstdio>
#include<iostream>
using namespace std;
struct q{
	int v,p;
}q[200002];
int dp[200002],sl,sr,n,l,r,a[200002];
int main()
{
	scanf("%d%d%d",&n,&sl,&sr);
	if(sl>sr)
	{
		swap(sl,sr);
	}
	for(int i=0;i<=n;++i)
	{
		scanf("%d",&a[i]);
		dp[i]=a[i];
	}
	for(int i=n+1;i>=sl;--i)
	{
		while(l<=r&&dp[i]>q[r].v)
		{
			--r;
		}
		++r;
		q[r].p=i;
		q[r].v=dp[i];
		dp[i-sl]=q[l].v+a[i-sl];
		if(i+sr==q[l].p)
		{
			++l;
		}
	}
	printf("%d",dp[0]);
	return 0;
}
