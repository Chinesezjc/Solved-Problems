//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,cnt,fa[100001],head[100001],T,x,y;
struct way{
	int next,to;
}way[200000];
void add(int f,int t)
{
	++cnt;
	way[cnt].to=t;
	way[cnt].next=head[f];
	head[f]=cnt;
}
void gettree(int now)
{
	for(int i=head[now];i;i=way[i].next)
	{
		if(fa[now]==way[i].to)
		{
			continue;
		}
		fa[way[i].to]=now;
		gettree(way[i].to);
	}
}
int dfs(int now)
{
	int sum=1,tmp;
	for(int i=head[now];i;i=way[i].next)
	{
		if(fa[now]==way[i].to)
		{
			continue;
		}
		tmp=dfs(way[i].to);
		if(tmp==-1)
		{
			return -1;
		}
		sum+=tmp;
	}
	if(sum>k)
	{
		return -1;
	}
	return sum%k;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>T;
	while(T)
	{
		--T;
		cin>>n>>k;
		cnt=0;
		fill(fa+1,fa+1+n,0);
		fill(head+1,head+1+n,0);
		for(int i=1;i<n;++i)
		{
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		gettree(1);
		cout<<(dfs(1)==-1?"NO":"YES")<<endl;
	}
	return 0;
}

