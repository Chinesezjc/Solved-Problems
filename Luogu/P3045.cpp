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
		swap(heap[1],heap[cnt--]);
		if(cnt==0)
		{
			return 0;
		}
		return push_down(1);
	}
	
	public:inline int length()
	{
		return cnt;
	}
	
	inline int push_up(int now)
	{
		while(now>1&&heap[now]>heap[now>>1])
		{
			swap(heap[now],heap[now>>1]);
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
				swap(heap[now],heap[nxt]);
				now=nxt;
			}
		}
		if(now<<1==cnt&&heap[now<<1]>heap[now])
		{
			swap(heap[now<<1],heap[now]);
		}
		return 0;
	}
};
struct A{
	int v,p;
	bool operator > (const A &X)const
	{
		return v>X.v;
	}
	bool operator < (const A &X)const
	{
		return v<X.v;
	}
}tmp;
int n,m,k,a[50001],b[50001],used[50001],use,ans;
MaxHeap <A,50000> s,t,l;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		used[i]=2;
		++ans;
		use+=a[i];
		tmp.p=i;
		tmp.v=a[i];
		s.push(tmp);
		tmp.v=a[i]-b[i];
		t.push(tmp);
	}
	k=min(k,n);
	for(int i=1;i<=k;++i)
	{
		tmp=t.top();
		t.pop();
		use-=tmp.v;
		used[tmp.p]=1;
		tmp.v=b[tmp.p];
		l.push(tmp);
	}
	while(use>m)
	{
		while(s.length()&&used[s.top().p]!=2)
		{
			s.pop();
		}
		while(t.length()&&used[t.top().p]!=2)
		{
			t.pop();
		}
		while(l.length()&&used[l.top().p]!=1)
		{
			l.pop();
		}
		if(s.length()&&s.top().v>t.top().v+l.top().v)
		{
			tmp=s.top();
			s.pop();
			use-=tmp.v;
			used[tmp.p]=0;
			--ans;
			continue;
		}
		if(t.length())
		{
			tmp=t.top();
			t.pop();
			use-=tmp.v;
			used[tmp.p]=1;
			tmp.v=b[tmp.p];
			l.push(tmp);
		}
		tmp=l.top();
		l.pop();
		use-=tmp.v;
		used[tmp.p]=0;
		--ans;
	}
	cout<<ans<<endl;
	return 0;
}
