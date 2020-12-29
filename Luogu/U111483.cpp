//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a,suma,sumb[300001],dp[2][300001],dl[300001],l,r,now,start[300001],v,cnt,ans=-INF;
struct boqi{
	int b,t;
	bool operator < (const boqi &A)const
	{
		return t==A.t?b<A.b:t<A.t;
	}
}b[301];
inline int jisuan(int s,int stand)
{
	return sumb[start[s]-1]+sumb[start[s+1]-1]-sumb[now]-sumb[now]+stand*(now+now-start[s]+2-start[s+1]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>v;
	for(int i=1;i<=m;++i)
	{
		cin>>b[i].b>>a>>b[i].t;
		suma+=a;
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=m;++i)
	{
		sumb[i]=sumb[i-1]+b[i].b;
		if(b[i].t!=b[i-1].t)
		{
			start[++cnt]=i;
		}
	}
	start[++cnt]=m+1;
	for(int i=1;i<=n;++i)
	{
		while(i>=b[now+1].b&&now<start[2]-1)
		{
			++now;
		}
		dp[1][i]=-jisuan(1,i);
	}
	for(int i=2;i<cnt;++i)
	{
		int L=i&1,R=min(n,(b[start[i]].t-b[start[i-1]].t)*v);
		l=r=0;
		for(int j=1;j<=R;++j)
		{
			while(l<r&&dp[!L][dl[r]]<=dp[!L][j])
			{
				--r;
			}
			dl[++r]=j;
		}
		for(int j=1;j<=n;++j)
		{
			int left=max(1ll,j-R),right=min(n,j+R);
			while(l<r&&dl[l+1]<left)
			{
				++l;
			}
			if(j+R<=n)
			{
				while(l<r&&dp[!L][dl[r]]<=dp[!L][right])
				{
					--r;
				}
				dl[++r]=right;
			}
			dp[L][j]=dp[!L][dl[l+1]];
			while(j>=b[now+1].b&&now<start[i+1]-1)
			{
				++now;
			}
			dp[L][j]-=jisuan(i,j);
		}
	}
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,dp[(cnt-1)&1][i]);
	}
	cout<<ans+suma;
	return 0;
}

