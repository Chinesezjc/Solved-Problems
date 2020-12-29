//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
vector <int> son[6005];
int dp[2][6005],ans,a[6005],n,l,k;
int dfs(int i,int cho)
{
	if(dp[cho][i])
	{
		return dp[cho][i];
	}
	int tmp=0;
	if(cho==0)
	{
		for(int j=0;j<son[i].size();++j)
		{
			tmp+=max(dfs(son[i][j],0),dfs(son[i][j],1));
		}
	}
	else
	{
		tmp+=a[i];
		for(int j=0;j<son[i].size();++j)
		{
			tmp+=dfs(son[i][j],0);
		}
	}
	return dp[cho][i]=tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;++i)
	{
		cin>>l>>k;
		son[k].push_back(l);
	}
	for(int i=1;i<=n;++i)
	{
		ans=max(max(dfs(i,0),dfs(i,1)),ans);
	}
	cout<<ans<<endl;
	return 0;
}

