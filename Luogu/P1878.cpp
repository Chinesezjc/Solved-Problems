#include<cstdio>
#include<iostream>
#define top() heap[1]
using namespace std;
int cnt,n,sum;
bool get()
{
	char c=getchar();
	while(c!='B'&&c!='G')
	{
		c=getchar();
	}
	c=='B'?++sum:--sum;
	return c=='B'?true:false;
}
struct heap{
	int l,r,v;
	bool operator < (heap tmp)const
	{
		return v==tmp.v?l<tmp.l:v<tmp.v;
	}
}heap[200002];
struct person{
	bool m,used;
	int v;
}person[200002];
void push(int x,int l,int r)
{
	++cnt;
	heap[cnt].l=l;
	heap[cnt].r=r;
	heap[cnt].v=x;
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
int abs(int x)
{
	return x<0?-x:x;
}
void mmm()
{
	for(int i=0;i<=n;++i)
	{
		printf("%d ",person[i].used);
	}
	puts("");
}
void nnn()
{
	
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		person[i].m=get();
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&person[i].v);
		person[i].used=false;
	}
	printf("%d\n",(n-abs(sum))/2);
	for(int i=1;i<n;++i)
	{
		if(person[i].m!=person[i+1].m)
		{
			push(abs(person[i].v-person[i+1].v),i,i+1);
		}
	}
	do
	{
		if(!person[top().l].used&&!person[top().r].used)
		{
			printf("%d %d\n",top().l,top().r);
			person[top().l].used=true;
			person[top().r].used=true;
			int l=top().l-1,r=top().r+1;
			pop();
			while(person[l].used)
			{
				--l;
			}
			while(person[r].used)
			{
				++r;
			}
			if(l==0||r==n+1)
			{
				continue;
			}
			if(person[l].m!=person[r].m&&!person[l].used&&!person[r].used)
			{
				push(abs(person[l].v-person[r].v),l,r);
			}
		}
		else
		{
			pop();
		}
	}
	while(cnt>0);
	return 0;
}
