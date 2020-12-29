#include<cstdio>
#include<algorithm>
using namespace std;
int n,A[100001],B[100001],cnt;
struct HEAP{
	int x,y,v;
	bool operator > (const HEAP tmp) const
	{
		return v>tmp.v;
	}
}heap[200001];
void pop()
{
	swap(heap[1],heap[cnt]);
	--cnt;
	int now=1,next=1;
	while(now<<1<cnt)
	{
		if(heap[next]>heap[now<<1])
		{
			next=now<<1;
		}
		if(heap[next]>heap[(now<<1)+1])
		{
			next=(now<<1)+1;
		}
		if(now!=next)
		{
			swap(heap[next],heap[now]);
			now=next;
		}
		else
		{
			return;
		}
	}
	if(now<<1==cnt&&heap[now]>heap[now<<1])
	{
		swap(heap[now],heap[now<<1]);
	}
}
void push(int a,int b,int c)
{
	++cnt;
	heap[cnt].x=a;
	heap[cnt].y=b;
	heap[cnt].v=c;
	int now=cnt;
	while(now>1&&heap[now>>1]>heap[now])
	{
		swap(heap[now],heap[now>>1]);
		now>>=1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&B[i]);
	}
	for(int i=1;i<=n;++i)
	{
		heap[i].x=i;
		heap[i].y=i;
		heap[i].v=A[i]+B[i];
	}
	cnt=n;
	for(int i=1;i<=n;++i)
	{
		printf("%d ",heap[1].v);
		int a=heap[1].x,b=heap[1].y;
		pop();
		if(a==b)
		{
			push(a+1,b,A[a+1]+B[b]);
			push(a,b+1,A[a]+B[b+1]);
		}
		if(a<b)
		{
			push(a,b+1,A[a]+B[b+1]);
		}
		if(a>b)
		{
			push(a+1,b,A[a+1]+B[b]);
		}
	}
	return 0;
}
