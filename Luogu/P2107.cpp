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
template <class t> void Swap(t &A,t &B)
{
	t TMP=A;
	A=B;
	B=TMP;
}
template <class t,int size> class MaxHeap
{
	t heap[size+1];
	int cnt;
	
	public:inline int push(const t x)
	{
		if(cnt==size)
		{
			return -1;
		}
		heap[++cnt]=x;
		return push_up(cnt);
	}
	
	public:inline t top()
	{
		return heap[1];
	}
	
	public:inline int pop()
	{
		if(cnt==0)
		{
			return -1;
		}
		Swap(heap[1],heap[cnt--]);
		return push_down(1);
	}
	
	inline int push_up(int now)
	{
		while(now>1&&heap[now]>heap[now>>1])
		{
			Swap(heap[now],heap[now>>1]);
			now>>=1;
		}
		return 0;
	}
	
	inline int push_down(int now)
	{
		int nxt;
		while(now<<1<cnt)
		{
			nxt=now;
			if(heap[now<<1]>heap[nxt])
			{
				nxt=now<<1;
			}
			if(heap[now<<1|1]>heap[nxt])
			{
				nxt=now<<1|1;
			}
			if(now==nxt)
			{
				return 0;
			}
			else
			{
				Swap(heap[now],heap[nxt]);
				now=nxt;
			}
		}
		if(now<<1==cnt&&heap[now<<1]>heap[now])
		{
			Swap(heap[now<<1],heap[now]);
		}
		return 0;
	}
};
struct XXX{
	int v,p;
	bool operator > (const XXX &x)const
	{
		return v>x.v;
	}
	bool operator < (const XXX &x)const
	{
		return v<x.v;
	}
}tmp;
struct computer_room{
	int t,x;
	bool operator < (const computer_room &X)const
	{
		return x<X.x;
	}
}c[100001];
using namespace std;
int n,m,now,use,ans;
MaxHeap <int,100000> s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i].x>>c[i].t;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;++i)
	{
		use+=c[i].x-c[i-1].x+c[i].t;
		++now;
		if(c[i].x>m)
		{
			break;
		}
		s.push(c[i].t);
		while(use>m)
		{
			--now;
			use-=s.top();
			s.pop();
		}
		ans=max(now,ans);
	}
	cout<<ans<<endl;
	return 0;
}

