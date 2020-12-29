//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,n;
int ans1(int A,int B,int N)
{
	int c[3];
	c[0]=min(N-1,A)*3+(N-1-min(N-1,A));
	if(min(N-1,A-B)>=0)
	{
		c[1]=min(N-1,A-B)*3+1+(N-1-min(N-1,A-B));
	}
	else
	{
		c[1]=-INF;
	}
	if(min(N-1,A-B-1)>=0)
	{
		c[2]=min(N-1,A-B-1)*3+3+(N-1-min(N-1,A-B-1));
	}
	else
	{
		c[2]=-INF;
	}
	return max(max(c[0],c[1]),c[2]);
}
int ans2(int A,int B,int N)
{
	int c[3];
	c[0]=3+(N-1)-min(N-1,B);
	if(min(N-1,B-A)>=0)
	{
		c[1]=1+(N-1)-min(N-1,B-A);
	}
	else
	{
		c[1]=INF;
	}
	if(min(N-1,B-A-1)>=0)
	{
		c[2]=0+(N-1)-min(N-1,B-A-1);
	}
	else
	{
		c[2]=INF;
	}
	return min(min(c[0],c[1]),c[2]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>a>>b>>n)
	{
		if(n==0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		cout<<ans1(a,b,n)<<' '<<ans2(a,b,n)<<endl;
	}
	return 0;
}

