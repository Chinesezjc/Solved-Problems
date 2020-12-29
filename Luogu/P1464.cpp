#include<cstdio>
using namespace std;
inline void rd(long long &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
long long a,b,c,dp[21][21][21];
long long w(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0)
	{
		return 1;
	}
	if(a>20||b>20||c>20)
	{
		return w(20,20,20);
	}
	if(dp[a][b][c])
	{
		return dp[a][b][c];
	}
	if(a<b&&b<c)
	{
		return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
	rd(a);
	rd(b);
	rd(c);
	while(a!=-1||b!=-1||c!=-1)
	{
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
		rd(a);
		rd(b);
		rd(c);
	}
	return 0;
}

