#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct way
{
    int next,to,v; 
} way[200001];
inline int min(int a,int b)
{
    return a<b?a:b;
}
inline int rd()
{
    char tmp=getchar();
    int ddd=0;
    while('0'>tmp&&tmp<'9')
    {
        tmp=getchar();
    }
    while('0'<=tmp&&tmp<='9')
    {
        ddd=(ddd<<3)+(ddd<<1)+tmp-'0';
        tmp=getchar();
    }
    return ddd;
}
struct HEAP{
	int p,dis;
	inline bool operator > (const HEAP &x)const
	{
		return dis>x.dis;
	}
}heap[20001],ts;
int n,m,num[2001],cnt,dis[2001],l,x,y,z,head[2001],f,t,nextn;
bool went[2001];
inline void push(HEAP ddd)
{
	heap[++l]=ddd;
	int now=l,fa=l>>1;
	while(now>1&&heap[fa]>heap[now])
	{
		swap(heap[now],heap[fa]);
		now=fa;
		fa=now>>1;
	}
}
inline int top()
{
	return heap[1].p;
}
inline void pop()
{
	heap[1]=heap[l--];
	int now=1,next=1,lson=2,rson=3;
	while(lson<l)
	{
		if(heap[next]>heap[lson])
		{
			next=lson;
		}
		if(heap[next]>heap[rson])
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
	if(lson==l&&heap[now]>heap[lson])
	{
		swap(heap[now],heap[lson]);
	}
}
inline void add(int a,int b,int c)
{
    ++cnt;
    way[cnt].next=head[a];
    way[cnt].to=b;
    way[cnt].v=c;
    head[a]=cnt;
}
int main()
{
    n=rd();
    m=rd();
    for(int i=1; i<=m; ++i)
    {
        x=rd();
        y=rd();
        z=rd();
        add(x,y,z);
        add(y,x,z);
    }
    fill(dis+1,dis+1+n,0x3fffffff);
    f=rd();
    t=rd();
    dis[f]=0;
    ts.dis=0;
    ts.p=f;
    push(ts);
    while(l>0)
    {
        nextn=top();
        pop();
        if(went[nextn])
        {
        	continue;
		}
        went[nextn]=true;
        for(int j=head[nextn]; j; j=way[j].next)
        {
        	ts.p=way[j].to;
        	ts.dis=dis[nextn]+way[j].v;
        	if(dis[ts.p]>ts.dis)
        	{
        		dis[ts.p]=ts.dis;
        		push(ts);
			}
        }
    }
    printf("%d",dis[t]>1000000000?-1:dis[t]);
    return 0;
}
