//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
vector <int> to[100001];
queue <int> que;
int n,m,a,b,ans[100001],d;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	d=n-1;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	fill(ans+2,ans+1+n,INF);
	que.push(1);
	while(!que.empty())
	{
		int now=que.front();
		que.pop();
		for(int i=0;i<to[now].size();++i)
		{
			if(ans[to[now][i]]==INF)
			{
				ans[to[now][i]]=now;
				--d;
				que.push(to[now][i]);
			}
		}
	}
	if(!d)
	{
		cout<<"Yes"<<endl;
		for(int i=2;i<=n;++i)
		{
			cout<<ans[i]<<endl;
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

