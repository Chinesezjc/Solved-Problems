//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a,b,c;
char cho[100001][5][5][5];
string s[100001];
void output(int N,int A,int B,int C)
{
	if(s[N]=="AB")
	{
		if(cho[N][A][B][C]=='A')
		{
			output(N-1,A-1,B+1,C);
			cout<<'A'<<endl;
		}
		if(cho[N][A][B][C]=='B')
		{
			output(N-1,A+1,B-1,C);
			cout<<'B'<<endl;
		}
	}
	if(s[N]=="AC")
	{
		if(cho[N][A][B][C]=='A')
		{
			output(N-1,A-1,B,C+1);
			cout<<'A'<<endl;
		}
		if(cho[N][A][B][C]=='C')
		{
			output(N-1,A+1,B,C-1);
			cout<<'C'<<endl;
		}
	}
	if(s[N]=="BC")
	{
		if(cho[N][A][B][C]=='B')
		{
			output(N-1,A,B-1,C+1);
			cout<<'B'<<endl;
		}
		if(cho[N][A][B][C]=='C')
		{
			output(N-1,A,B+1,C-1);
			cout<<'C'<<endl;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>a>>b>>c;
	a=min(2ll,a);
	b=min(2ll,b);
	c=min(2ll,c);
	cho[0][a][b][c]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		if(s[i]=="AB")
		{
			for(int A=0;A<4;++A)
			{
				for(int B=0;B<4;++B)
				{
					for(int C=0;C<4;++C)
					{
						if(A>0&&cho[i-1][A-1][B+1][C])
						{
							cho[i][A][B][C]='A';
						}
						if(B>0&&cho[i-1][A+1][B-1][C])
						{
							cho[i][A][B][C]='B';
						}
					}
				}
			}
		}
		if(s[i]=="AC")
		{
			for(int A=0;A<4;++A)
			{
				for(int B=0;B<4;++B)
				{
					for(int C=0;C<4;++C)
					{
						if(A>0&&cho[i-1][A-1][B][C+1])
						{
							cho[i][A][B][C]='A';
						}
						if(C>0&&cho[i-1][A+1][B][C-1])
						{
							cho[i][A][B][C]='C';
						}
					}
				}
			}
		}
		if(s[i]=="BC")
		{
			for(int A=0;A<4;++A)
			{
				for(int B=0;B<4;++B)
				{
					for(int C=0;C<4;++C)
					{
						if(B>0&&cho[i-1][A][B-1][C+1])
						{
							cho[i][A][B][C]='B';
						}
						if(C>0&&cho[i-1][A][B+1][C-1])
						{
							cho[i][A][B][C]='C';
						}
					}
				}
			}
		}
	}
	for(int A=0;A<4;++A)
	{
		for(int B=0;B<4;++B)
		{
			for(int C=0;C<4;++C)
			{
				if(cho[n][A][B][C])
				{
					cout<<"Yes"<<endl;
					output(n,A,B,C);
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}

