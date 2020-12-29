//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int SG[201][201],n,m;
int getSG(int x,int y)
{
	if(SG[x][y]!=-1)
	{
		return SG[x][y];
	}
	bool v[10];
	fill(v,v+10,false);
	for(int i=2;i<=x-i;++i)
	{
		v[getSG(i,y)^getSG(x-i,y)]=true;
	}
	for(int i=2;i<=y-i;++i)
	{
		v[getSG(x,i)^getSG(x,y-i)]=true;
	}
	for(int i=0;i<10;++i)
	{
		if(!v[i])
		{
			return SG[x][y]=i;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=200;++i)
	{
		for(int j=1;j<=200;++j)
		{
			SG[i][j]=-1;
		}
	}
	while(cin>>n>>m)
	{
		if(n==1||m==1)
		{
			cout<<"WIN"<<endl;
		}
		else
		{
			cout<<(getSG(n,m)?"WIN":"LOSE")<<endl;
		}
	}
	return 0;
}

