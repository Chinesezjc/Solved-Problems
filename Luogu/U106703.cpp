//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,s,fa[10001],len[10001],a,b,c;
int find(int now)
{
	if(now==fa[now])
	{
		return now;
	}
	int tmp=fa[now];
	fa[now]=find(fa[now]);
	len[now]+=len[tmp];
	return fa[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		--a;
		int A=find(a),B=find(b);
		if(A<B)
		{
			fa[B]=A;
			len[B]=len[a]+c-len[b];
		}
		else
		{
			fa[A]=B;
			len[A]=len[b]-len[a]-c;
		}
	}
	cin>>s;
	for(int i=1;i<=s;++i)
	{
		cin>>a>>b;
		--a;
		if(find(a)!=find(b))
		{
			cout<<"Too Hard"<<endl;
		}
		else
		{
			cout<<len[b]-len[a]<<endl;
		}
	}
	return 0;
}

