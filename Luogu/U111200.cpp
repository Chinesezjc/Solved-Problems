//This code was made by Chinese_zjc_.
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dp[100001],from[100001],n,m,ans[101],a[101],b[101],N,M,tmp,dp2[2000000],from2[2000000];
bool cmp(int L,int R)
{
	tmp=L;
	int Ans[101];
	fill(Ans+1,Ans+1+m,0);
	while(tmp>0)
	{
		++Ans[from[tmp]];
		tmp-=a[from[tmp]];
	}
	tmp=R;
	while(tmp>0)
	{
		--Ans[from[tmp]];
		tmp-=a[from[tmp]];
	}
	for(int i=1;i<=m;++i)
	{
		if(Ans[i]>0)
		{
			return false;
		}
		if(Ans[i]<0)
		{
			return true;
		}
	}
	return false;
}
bool cmp2(int L,int R)
{
	tmp=L;
	int Ans[101];
	fill(Ans+1,Ans+1+m,0);
	while(tmp>0)
	{
		++Ans[from2[tmp]];
		tmp-=b[from2[tmp]];
	}
	tmp=R;
	while(tmp>0)
	{
		--Ans[from2[tmp]];
		tmp-=b[from2[tmp]];
	}
	for(int i=1;i<=m;++i)
	{
		if(Ans[i]>0)
		{
			return false;
		}
		if(Ans[i]<0)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i]>>b[i];
	}
	fill(dp+1,dp+1+n,-INF);
	for(int i=1;i<=m;++i)
	{
		if(a[i]>=b[i])
		{
			continue;
		}
		for(int j=a[i];j<=n;++j)
		{
			if(dp[j]<dp[j-a[i]]+b[i])
			{
				from[j]=i;
				dp[j]=dp[j-a[i]]+b[i];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(dp[N]+n-N<dp[i]+n-i||(dp[N]+n-N==dp[i]+n-i&&cmp(N,i)))
		{
			N=i;
		}
	}
	tmp=N;
	while(tmp>0)
	{
		++ans[from[tmp]];
		tmp-=a[from[tmp]];
	}
	N=dp[N]+n-N;
	fill(dp2+1,dp2+1+N,-INF);
	dp2[0]=0;
	for(int i=1;i<=m;++i)
	{
		if(a[i]<=b[i])
		{
			continue;
		}
		for(int j=b[i];j<=N;++j)
		{
			if(dp2[j]<dp2[j-b[i]]+a[i])
			{
				from2[j]=i;
				dp2[j]=dp2[j-b[i]]+a[i];
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		if(dp2[M]+N-M<dp2[i]+N-i||(dp2[M]+N-M==dp2[i]+N-i&&cmp2(M,i)))
		{
			M=i;
		}
	}
	tmp=M;
	while(tmp>0)
	{
		--ans[from2[tmp]];
		tmp-=b[from2[tmp]];
	}
	M=dp2[M]+N-M;
	cout<<M-n<<endl;
	for(int i=1;i<=m;++i)
	{
		if(ans[i]==0)
		{
			cout<<"Buy 0"<<endl;
		}
		if(ans[i]<0)
		{
			cout<<"Buy "<<-ans[i]<<" from Skellige"<<endl;
		}
		if(ans[i]>0)
		{
			cout<<"Buy "<<ans[i]<<" from Toussaint"<<endl;
		}
	}
	return 0;
}

