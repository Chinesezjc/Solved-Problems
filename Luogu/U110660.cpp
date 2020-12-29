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
int t,n,to[100001],ans,start;
vector <int> from[100001];
bool f[100001];
void ring(int now,int depth)
{
	if(now==start&&depth)
	{
		ans=max(ans,depth);
		return;
	}
	for(int i=0;i<from[now].size();++i)
	{
		if((!f[from[now][i]])||(start==from[now][i]))
		{
			f[from[now][i]]=true;
			ring(from[now][i],depth+1);
		}
	}
}
int length(int now)
{
	int tmp=0;
	for(int i=0;i<from[now].size();++i)
	{
		if(!f[from[now][i]])
		{
			f[from[now][i]]=true;
			tmp=max(tmp,length(from[now][i]));
		}
	}
	return tmp+1;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			from[i].clear();
			f[i]=false;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>to[i];
			from[to[i]].push_back(i);
		}
		for(int i=1;i<=n;++i)
		{
			if(!f[i]&&i==to[to[i]])
			{
				f[i]=true;
				f[to[i]]=true;
				ans+=length(i)+length(to[i]);
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(!f[i])
			{
				start=i;
				f[i]=true;
				ring(i,0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

