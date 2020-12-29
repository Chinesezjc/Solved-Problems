#include<cstdio>
#include<iostream>
#define top heap[1]
using namespace std;
long long heap[50001],cnt,x,y,n,ans;
void push(long long tmp)
{
	++cnt;
	heap[cnt]=tmp;
	int now=cnt;
	while(now>1&&heap[now]<heap[now>>1])
	{
		swap(heap[now],heap[now>>1]);
		now>>=1;
	}
}
void pop()
{
	swap(heap[1],heap[cnt]);
	--cnt;
	int now=1,next=1;
	while(now<<1<cnt)
	{
		if(heap[now<<1]<heap[next])
		{
			next=now<<1;
		}
		if(heap[(now<<1)+1]<heap[next])
		{
			next=(now<<1)+1;
		}
		if(now!=next)
		{
			swap(heap[now],heap[next]);
			now=next;
		}
		else
		{
			return;
		}
	}
	if(now<<1==cnt&&heap[now<<1]<heap[now])
	{
		swap(heap[now],heap[now<<1]);
	}
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&x);
		push(x);
	}
	while(cnt>1)
	{
		x=top;
		pop();
		y=top;
		pop();
		ans+=x+y;
		push(x+y);
	}
	printf("%lld",ans);
	return 0;
}
