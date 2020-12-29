//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n;
char p;
struct TREE{
	char lson,rson;
	int s;
	TREE()
	{
		lson=rson=s=0;
	}
}tree[129];
void go(char i)
{
	cout<<i;
	if(tree[i].lson)
	{
		go(tree[i].lson);
	}
	if(tree[i].rson)
	{
		go(tree[i].rson);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		do
		{
			cin>>p;
		}
		while(p=='\n');
		cin>>tree[p].lson>>tree[p].rson;
		++tree[p].s;
		if(tree[p].lson!='*')
		{
			++tree[tree[p].lson].s;
		}
		else
		{
			tree[p].lson=0;
		}
		if(tree[p].rson!='*')
		{
			++tree[tree[p].rson].s;
		}
		else
		{
			tree[p].rson=0;
		}
	}
	for(char i=0;i<127;++i)
	{
		if(tree[i].s==1)
		{
			go(i);
		}
	}
	return 0;
}

