//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a,b;
int where[26],len,nextn;
struct TREE{
	int lson,rson;
	TREE()
	{
		lson=rson=-1;
	}
}tree[26];
void build(int now,int l,int r)
{
	--nextn;
	if(where[b[nextn]-'A']>where[b[now]-'A']&&where[b[nextn]-'A']<=r)
	{
		tree[b[now]-'A'].rson=b[nextn]-'A';
		build(nextn,where[b[now]-'A']+1,r);
	}
	if(where[b[nextn]-'A']<where[b[now]-'A']&&where[b[nextn]-'A']>=l)
	{
		tree[b[now]-'A'].lson=b[nextn]-'A';
		build(nextn,l,where[b[now]-'A']-1);
	}
}
void in_front_of(int now)
{
	cout<<(char)(now+'A');
	if(tree[now].lson!=-1)
	{
		in_front_of(tree[now].lson);
	}
	if(tree[now].rson!=-1)
	{
		in_front_of(tree[now].rson);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	len=a.length();
	for(int i=0;i<len;++i)
	{
		where[a[i]-'A']=i;
	}
	nextn=len-1;
	build(len-1,0,len-1);
	in_front_of(b[len-1]-'A');
	return 0;
}
