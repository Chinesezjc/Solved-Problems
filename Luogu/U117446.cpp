//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define INF 0x3fffffff
using namespace std;
int t,n,l[41],sum;
bool cho[41];
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
}
bool dfs(int now,int len,int times)
{
	if(times==4)
	{
		return true;
	}
	if(len>sum)
	{
		return false;
	}
	if(len==sum)
	{
		return dfs(n,0,times+1);
	}
	if(!now)
	{
		return false;
	}
	for(int i=now;i>0;--i)
	{
		if(cho[i])
		{
			continue;
		}
		if(len+l[i]>sum)
		{
			continue;
		}
		cho[i]=true;
		if(dfs(i-1,len+l[i],times))
		{
			return true;
		}
		cho[i]=false;
		if(now==n)
		{
			return false;
		}
		while(l[i]==l[i-1])
		{
			--i;
		}
	}
	return false;
}
signed main()
{
	read(t);
	while(t)
	{
		--t;
		read(n);
		sum=0;
		for(int i=1;i<=n;++i)
		{
			read(l[i]);
			sum+=l[i];
			cho[i]=false;
		}
		if(sum%4!=0)
		{
			puts("no");
			continue;
		}
		sort(l+1,l+1+n);
		sum/=4;
		if(sum<l[n])
		{
			puts("no");
			continue;
		}
		if(dfs(n,0,1))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}

