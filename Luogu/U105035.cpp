//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
char a;
int b,c,n,fa[30001],ans[30001],son[30001];
int find(int now)
{
	if(fa[now]==now)
	{
		return now;
	}
	int tmp=fa[now];
	fa[now]=find(tmp);
	ans[now]+=ans[tmp];
	return fa[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=30000;++i)
	{
		fa[i]=i;
		son[i]=i;
	}
	while(n)
	{
		--n;
		cin>>a;
		if(a=='M')
		{
			cin>>b>>c;
			int tmp=find(b);
			fa[tmp]=son[find(c)];
			++ans[tmp];
			son[find(c)]=son[tmp];
			find(tmp);
		}
		if(a=='C')
		{
			cin>>b;
			find(b);
			cout<<ans[b]<<endl;
		}
	}
	return 0;
}

