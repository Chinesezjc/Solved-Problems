//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s;
int sum[1<<11],n,m,tree[1<<12];
void build(int now,int l,int r)
{
	tree[now]=(sum[r]-sum[l-1]==r-l+1?1:(sum[r]-sum[l-1]==0?0:-1));
	if(r==l)
	{
		return;
	}
	build(now<<1,l,(l+r)>>1);
	build((now<<1)+1,((l+r)>>1)+1,r);
}
void behind(int now)
{
	if(now<<1<=m)
	{
		behind(now<<1);
	}
	if(now<<1<=m-1)
	{
		behind((now<<1)+1);
	}
	cout<<(tree[now]==1?'I':(tree[now]==0?'B':'F'));
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s;
	m=1<<n;
	for(int i=1;i<=m;++i)
	{
		sum[i]=sum[i-1]+(s[i-1]=='1');
	}
	build(1,1,m);
	m<<=1;
	--m;
	behind(1);
	return 0;
}

