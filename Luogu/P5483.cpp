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
int t,n,m,l,now,h;
string s[105][10005],tmp,a;
char c;
void read(string &A)
{
	A="";
	c=getchar();
	while(c==','||c=='\n')
	{
		c=getchar();
	}
	while(c!=','&&c!='\n')
	{
		A+=c;
		c=getchar();
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>h>>tmp;
		s[1][m+1]=tmp;
		n=max(n,1+h);
		l=1;
		for(int i=2;i<=h+1;++i)
		{
			cin>>tmp;
			now=0;
			a="";
			for(int j=0;j<tmp.length();++j)
			{
				if(tmp[j]==',')
				{
					s[i][(++now)+m]=a;
					a="";
				}
				else
				{
					a+=tmp[j];
				}
			}
			s[i][(++now)+m]=a;
			l=max(l,now);
		}
		m+=l;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<s[i][j]<<",\n"[j==m];
		}
	}
	return 0;
}

