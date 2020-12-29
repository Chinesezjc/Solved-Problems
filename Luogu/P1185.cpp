//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,n,m,c,k;
bool yes[8000];
char s[1200][3200];
void kill(int now)
{
	if(now>=1<<n)
	{
		return;
	}
	yes[now]=false;
	kill(now<<1);
	kill(now<<1|1);
}
void work(int deep,int now,int x,int y)
{
	s[x][y]='o';
	if(yes[now<<1])
	{
		int len=((c-x)>>1);
		for(int i=1;i<=len;++i)
		{
			s[x+i][y-i]='/';
		}
		work(deep+1,now<<1,x+len+1,y-len-1);
	}
	if(yes[now<<1|1])
	{
		int len=((c-x)>>1);
		for(int i=1;i<=len;++i)
		{
			s[x+i][y+i]='\\';
		}
		work(deep+1,now<<1|1,x+len+1,y+len+1);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	fill(yes+1,yes+(1<<n),true);
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b;
		kill((1<<a>>1)+b-1);
	}
	c=3<<n>>2;
	k=(((1<<n>>1)|(1<<n>>2))<<1)-1;
//	cout<<c<<' '<<k<<endl;
	for(int i=1;i<=c;++i)
	{
		for(int j=1;j<=k;++j)
		{
			s[i][j]=' ';
		}
	}
	if(yes[1])
	{
		work(1,1,1,(k>>1)+1);
	}
	for(int i=1;i<=c;++i)
	{
		for(int j=1;j<=k;++j)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;
}

