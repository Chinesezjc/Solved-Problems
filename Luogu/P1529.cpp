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
int s[500][500],m,c,A,B,ans=1;
char a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m;
	for(int i=1;i<=52;++i)
	{
		for(int j=1;j<=52;++j)
		{
			s[i][j]=INF;
		}
		s[i][i]=0;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		if('A'<=a&&a<='Z')
		{
			A=a-'A'+1;
		}
		else
		{
			A=a-'a'+27;
		}
		if('A'<=b&&b<='Z')
		{
			B=b-'A'+1;
		}
		else
		{
			B=b-'a'+27;
		}
		s[A][B]=s[B][A]=min(s[A][B],c);
	}
	for(int k=1;k<=52;++k)
	{
		for(int i=1;i<=52;++i)
		{
			for(int j=1;j<=52;++j)
			{
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	for(int i=2;i<=25;++i)
	{
		if(s[ans][26]>s[i][26])
		{
			ans=i;
		}
	}
	cout<<(char)(ans+'A'-1)<<' '<<s[ans][26]<<endl;
	return 0;
}

