//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,ans;
void dfs(int now,int left,int i)
{
	if(left==1)
	{
		++ans;
		return;
	}
	while(i*left<=now)
	{
		dfs(now-i,left-1,i);
		++i;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	dfs(n,k,1);
	cout<<ans<<endl;
	return 0;
}

