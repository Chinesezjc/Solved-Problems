#include<cstdio>
#include<iostream>
#define top() heap[1].v
using namespace std;
int n,m,cnt,to[10001];
struct function{
	int a,b,c,it,now;
}function[10001];
struct heap{
	int v,to;
}heap[10001];
void push(int x,int f)
{
	++cnt;
	heap[cnt].v=x;
	heap[cnt].to=f;
	function[f].it=cnt;
	int now=cnt;
	while(now>1&&heap[now].v<heap[now>>1].v)
	{
		swap(heap[now],heap[now>>1]);
		function[heap[now].to].it=now>>1;
		function[heap[now>>1].to].it=now;
		now>>=1;
	}
}
void pop()
{
	swap(heap[1],heap[cnt]);
	--cnt;
	function[heap[1].to].it=1;
	int now=1,next=1;
	while(now<<1<cnt)
	{
		if(heap[next].v>heap[now<<1].v)
		{
			next=now<<1; 
		}
		if(heap[next].v>heap[(now<<1)+1].v)
		{
			next=(now<<1)+1;
		}
		if(now!=next)
		{
			swap(heap[now],heap[next]);
			function[heap[now].to].it=next;
			function[heap[next].to].it=now;
			now=next;
		}
		else
		{
			return;
		}
	}
	if(now<<1==cnt&&heap[now].v>heap[now<<1].v)
	{
		swap(heap[now],heap[now<<1]);
		function[heap[now].to].it=now;
		function[heap[now<<1].to].it=now<<1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&function[i].a,&function[i].b,&function[i].c);
		++function[i].now;
		push(function[i].a+function[i].b+function[i].c,i);
	}
	for(int i=1;i<=m;++i)
	{
		printf("%d ",top());
		++function[heap[1].to].now;
		push(function[heap[1].to].now*function[heap[1].to].now*function[heap[1].to].a+function[heap[1].to].now*function[heap[1].to].b+function[heap[1].to].c,heap[1].to);
		pop();
	}
	return 0;
}
