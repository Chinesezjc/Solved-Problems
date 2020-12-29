//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3ffffffffff
using namespace std;
int n,fa[1501],a,b,c,w[1501],FATHER,dp[1501][3];
vector <int> son[1501];
void dfs(int now)
{
	if(son[now].size()==0)
	{
		dp[now][1]=w[now];
		dp[now][0]=INF;
		dp[now][2]=0;
		return;
	}
	for(int i=0;i<son[now].size();++i)
	{
		dfs(son[now][i]);
		dp[now][0]+=min(dp[son[now][i]][0],dp[son[now][i]][1]);
		dp[now][1]+=min(min(dp[son[now][i]][0],dp[son[now][i]][1]),dp[son[now][i]][2]);
		dp[now][2]+=dp[son[now][i]][0];
	}
	int tmp=INF;
	for(int i=0;i<son[now].size();++i)
	{
		tmp=min(tmp,dp[son[now][i]][1]-min(dp[son[now][i]][0],dp[son[now][i]][1]));
	}
	dp[now][0]+=tmp;
	dp[now][1]+=w[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b>>c;
		son[a].resize(c);
		w[a]=b;
		for(int j=0;j<c;++j)
		{
			cin>>son[a][j];
			fa[son[a][j]]=a;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(fa[i]==0)
		{
			FATHER=i;
			break;
		}
	}
	dfs(FATHER);
	cout<<min(dp[FATHER][0],dp[FATHER][1])<<endl;
	return 0;
}

