//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
priority_queue<int,vector<int>,less<int> >big;
priority_queue<int,vector<int>,greater<int> >small;
int n,X,mid;
void read(int &x)
{
	x=0;
	int l=1;
	char c=getchar();
	while(('0'>c||c>'9')&&c!='-')
	{
		c=getchar();
	}
	if(c=='-')
	{
		l=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	x*=l;
}
signed main()
{
	read(n);
	read(mid);
	cout<<mid<<endl;
	for(int i=1;i<n;++i)
	{
		read(X);
		if(mid>X)
		{
			big.push(X);
		}
		else
		{
			small.push(X);
		}
		while(big.size()<small.size())
		{
			big.push(mid);
			mid=small.top();
			small.pop();
		}
		while(big.size()>small.size())
		{
			small.push(mid);
			mid=big.top();
			big.pop();
		}
		cout<<mid<<endl;
	}
	return 0;
}

