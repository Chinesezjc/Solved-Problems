//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct EDGE{
	int n,t;
}e[50001];
int fa[20001],n,m,low[20001],dfn[20001],id,cnt,stack[20001],ans1,ans2,head[20001],top,t,x,y;
bool ins[20001],in[20001],out[20001];
void Tarjan(int now)
{
	ins[now]=true;
	dfn[now]=low[now]=++id;
	stack[++top]=now;
	for(int i=head[now];i;i=e[i].n)
	{
		if(!dfn[e[i].t])
		{
			Tarjan(e[i].t);
			low[now]=min(low[now],low[e[i].t]);
		}
		else if(ins[e[i].t])
		{
			low[now]=min(low[now],low[e[i].t]);
		}
	}
	if(low[now]==dfn[now])
	{
		++cnt;
		fa[now]=cnt;
		while(stack[top]!=now)
		{
			fa[stack[top]]=cnt;
			ins[stack[top]]=false;
			--top;
		}
		--top;
		ins[now]=false;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>m;
		fill(low+1,low+1+n,0);
		fill(dfn+1,dfn+1+n,0);
		fill(head+1,head+1+n,0);
		fill(in+1,in+1+n,false);
		fill(out+1,out+1+n,false);
		ans1=ans2=cnt=id=top=0;
		for(int i=1;i<=m;++i)
		{
			cin>>x>>y;
			e[i].n=head[x];
			e[i].t=y;
			head[x]=i;
		}
		for(int i=1;i<=n;++i)
		{
			if(!dfn[i])
			{
				Tarjan(i);
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=head[i];j;j=e[j].n)
			{
				if(fa[i]==fa[e[j].t])
				{
					continue;
				}
				in[fa[i]]=true;
				out[fa[e[j].t]]=true;
			}
		}
		for(int i=1;i<=cnt;++i)
		{
			if(!in[i])
			{
				++ans1;
			}
			if(!out[i])
			{
				++ans2;
			}
		}
		if(cnt>1)
		{
			cout<<max(ans1,ans2)<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}

