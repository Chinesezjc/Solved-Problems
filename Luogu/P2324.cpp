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
#define START 1
#define END -1
using namespace std;
const int xx[8]={1,2,2,1,-1,-2,-2,-1},yy[8]={-2,-1,1,2,2,1,-1,-2};
struct p{
	int from,hash,x,y,step;
	inline bool operator < (const p &X)const
	{
		return hash==X.hash?(x==X.x?y<X.y:x<X.x):hash<X.hash;
	}
	inline char get(int X,int Y)const
	{
		if(X==x&&Y==y)
		{
			return '*';
		}
		else
		{
			return ((hash&(1ll<<(X*5+Y)))&&true)+'0';
		}
	}
	inline int operator = (const string X)
	{
		hash=0;
		for(int i=0;i<X.length();++i)
		{
			hash|=(X[i]-'0')<<i;
		}
	}
}start,End;
map<p,pair<int,int> >came;
queue<p>que;
string in;
int inx,iny,ans;
void bfs(p now)
{
	for(int i=0;i<8;++i)
	{
		p to=now;
		to.x=now.x+xx[i];
		to.y=now.y+yy[i];
		++to.step;
		if(to.x<=0||to.y<=0||to.x>5||to.y>5)
		{
			continue;
		}
		if(now.get(to.x,to.y)=='1')
		{
			to.hash^=((1ll<<(to.x*5+to.y))|(1ll<<(now.x*5+now.y)));
		}
		pair<int,int> tmp=came[to];
		if(tmp.first+to.from==0)
		{
			ans=tmp.second+to.step;
			if(ans>15)
			{
				ans=-1;
			}
			while(!que.empty())
			{
				que.pop();
			}
			return;
		}
		if(!tmp.first)
		{
			came[to]=pair<int,int>(to.from,to.step);
			que.push(to);
		}
	}
}
int t;
signed main()
{
	std::ios::sync_with_stdio(false);
	End=in="0000001111101111000110000100000";
	End.x=3;
	End.y=3;
	End.step=0;
	End.from=END;
	cin>>t;
	while(t)
	{
		--t;
		came.clear();
		while(!que.empty())
		{
			que.pop();
		}
		for(int i=1;i<=5;++i)
		{
			for(int j=1;j<=5;++j)
			{
				cin>>in[i*5+j];
				if(in[i*5+j]=='*')
				{
					in[i*5+j]='0';
					inx=i;
					iny=j;
				}
			}
		}
		start=in;
		start.x=inx;
		start.y=iny;
		start.from=START;
		start.step=0;
		came[start]=pair<int,int>(START,0);
		came[End]=pair<int,int>(END,0);
		que.push(start);
		que.push(End);
		ans=-1;
		while(!que.empty()&&que.front().step<=8)
		{
			p nxt=que.front();
			que.pop();
			bfs(nxt);
		}
		cout<<ans<<endl;
	}
	return 0;
}

