//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[100001],s[100001],now,nown,ans,ansn,bl,sl;
bool went[100001];
struct HEAP{
	int p,dis;
	inline bool operator < (const HEAP &x)const
	{
		return dis<x.dis;
	}
}big[100001],small[100001],ts;
inline void push(HEAP ddd,HEAP heap[],int &l)
{
	heap[++l]=ddd;
	int now=l,fa=l>>1;
	while(now>1&&heap[fa]<heap[now])
	{
		swap(heap[now],heap[fa]);
		now=fa;
		fa=now>>1;
	}
}
inline HEAP top(HEAP heap[])
{
	return heap[1];
}
inline void pop(HEAP heap[],int &l)
{
	heap[1]=heap[l--];
	int now=1,next=1,lson=2,rson=3;
	while(lson<l)
	{
		if(heap[next]<heap[lson])
		{
			next=lson;
		}
		if(heap[next]<heap[rson])
		{
			next=rson;
		}
		if(now==next)
		{
			return;
		}
		swap(heap[now],heap[next]);
		now=next;
		lson=now<<1;
		rson=lson+1;
	}
	if(lson==l&&heap[now]<heap[lson])
	{
		swap(heap[now],heap[lson]);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		ts.dis=a[i]+s[i]+s[i];
		ts.p=i;
		push(ts,big,bl);
	}
	for(int i=1;i<=n;++i)
	{
		while(went[top(small).p]&&sl>0)
		{
			pop(small,sl);
		}
		while((top(big).p<=nown||went[top(big).p])&&bl>0)
		{
			pop(big,bl);
		}
		ansn=top(big).p;
		ans=top(small).dis;
		if(ans>a[ansn]+((s[ansn]-s[nown])<<1))
		{
			cout<<(now+=ans)<<endl;
			went[top(small).p]=true;
		}
		else
		{
			cout<<(now+=a[ansn]+((s[ansn]-s[nown])<<1))<<endl;
			went[ansn]=true;
			do
			{
				ts.p=nown;
				ts.dis=a[nown];
				push(ts,small,sl);
				++nown;
			}
			while(nown<ansn);
		}
	}
	return 0;
}

