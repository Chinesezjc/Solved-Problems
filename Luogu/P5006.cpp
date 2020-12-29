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
char s[105][105];
int n,m,pde,pst,php,mhp,mde,mst,x,y,q,op;
const int xx[]={0,0,0,-1,1},yy[]={0,-1,1,0,0};
int up(double X)
{
	return ((int)X<X)?((int)X+1):X;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>s[i][j];
		}
	}
	cin>>mhp>>mst>>mde>>x>>y>>pst>>pde>>q;
	while(q)
	{
		--q;
		cin>>op;
		if(op==1)
		{
			cout<<php<<' '<<pst<<' '<<pde<<endl;
		}
		else
		{
			cin>>op;
			x+=xx[op];
			y+=yy[op];
			if(s[x][y]=='M')
			{
				php+=max(1ll,up(mhp*1.0/max(1ll,pst-mde))*max(1ll,mst-pde));
			}
			if(s[x][y]=='Q')
			{
				pst+=5;
			}
			if(s[x][y]=='Y')
			{
				pde+=5;
			}
			if(s[x][y]=='R')
			{
				php=max(0ll,php-10);
			}
		}
	}
	return 0;
}

