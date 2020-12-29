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
int x,y,t,n;
char s[10][10];
string now;
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=8;++i)
	{
		for(int j=1;j<=8;++j)
		{
			cin>>s[i][j];
			if(s[i][j]=='^')
			{
				t=1;
				x=i;
				y=j;
				s[i][j]=' ';
			}
			if(s[i][j]=='>')
			{
				t=2;
				x=i;
				y=j;
				s[i][j]=' ';
			}
			if(s[i][j]=='v')
			{
				t=3;
				x=i;
				y=j;
				s[i][j]=' ';
			}
			if(s[i][j]=='<')
			{
				t=4;
				x=i;
				y=j;
				s[i][j]=' ';
			}
		}
	}
	while(cin>>now)
	{
		if(now=="#")
		{
			for(int i=1;i<=8;++i)
			{
				for(int j=1;j<=8;++j)
				{
					if(s[i][j]==' ')
					{
						if(t==1)
						{
							cout<<'^';
						}
						if(t==2)
						{
							cout<<'>';
						}
						if(t==3)
						{
							cout<<'v';
						}
						if(t==4)
						{
							cout<<'<';
						}
					}
					else
					{
						cout<<s[i][j];
					}
				}
				cout<<endl;
			}
			return 0;
		}
		if(now=="move")
		{
			cin>>n;
			for(int i=1;i<=n;++i)
			{
				if(t==1)
				{
					int len=0;
					while(x-len-1>0&&s[x-len-1][y]!='.')
					{
						++len;
					}
					if(len)
					{
						for(int i=len;i>=0;--i)
						{
							s[x-i-1][y]=s[x-i][y];
						}
						s[x][y]='.';
						--x;
					}
					else
					{
						if(x>1&&s[x-1][y]=='.')
						{
							swap(s[x-1][y],s[x][y]);
							--x;
						}
					}
				}
				if(t==2)
				{
					int len=0;
					while(y+len+1<9&&s[x][y+len+1]!='.')
					{
						++len;
					}
					if(len)
					{
						for(int i=len;i>=0;--i)
						{
							s[x][y+i+1]=s[x][y+i];
						}
						s[x][y]='.';
						++y;
					}
					else
					{
						if(y<8&&s[x][y+1]=='.')
						{
							swap(s[x][y+1],s[x][y]);
							++y;
						}
					}
				}
				if(t==3)
				{
					int len=0;
					while(x+len+1<9&&s[x+len+1][y]!='.')
					{
						++len;
					}
					if(len)
					{
						for(int i=len;i>=0;--i)
						{
							s[x+i+1][y]=s[x+i][y];
						}
						s[x][y]='.';
						++x;
					}
					else
					{
						if(x<8&&s[x+1][y]=='.')
						{
							swap(s[x+1][y],s[x][y]);
							++x;
						}
					}
				}
				if(t==4)
				{
					int len=0;
					while(y-len-1>0&&s[x][y-len-1]!='.')
					{
						++len;
					}
					if(len)
					{
						for(int i=len;i>=0;--i)
						{
							s[x][y-i-1]=s[x][y-i];
						}
						s[x][y]='.';
						--y;
					}
					else
					{
						if(y>1&&s[x][y-1]=='.')
						{
							swap(s[x][y-1],s[x][y]);
							--y;
						}
					}
				}
			}
		}
		if(now=="turn")
		{
			cin>>now;
			if(now=="right")
			{
				++t;
				if(t==5)
				{
					t=1;
				}
			}
			if(now=="left")
			{
				--t;
				if(t==0)
				{
					t=4;
				}
			}
			if(now=="back")
			{
				t+=2;
				if(t==6)
				{
					t=2;
				}
				if(t==5)
				{
					t=1;
				}
			}
		}
	}
	return 0;
}

