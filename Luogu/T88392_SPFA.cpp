#include<cstdio>
using namespace std;
struct WAY{
	int next,to,v;
}way[200001];
int n,m,f,t,cnt,que[2001],x,y,z,dis[2001],now,head[2001],l,r;
bool in[2001];
inline void add(int a,int b,int c)
{
	++cnt;
	way[cnt].next=head[a];
	way[cnt].to=b;
	way[cnt].v=c;
	head[a]=cnt;
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
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	return ddd;
}
int main()
{
	n=rd();
	m=rd();
	for(int i=1;i<=m;++i)
	{
		x=rd();
		y=rd();
		z=rd();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;++i)
	{
		dis[i]=0x3fffffff;
	}
	f=rd();
	t=rd();
	dis[f]=0;
	que[++r]=f;
	in[f]=true;
	while(l<r)
	{
		in[que[++l%2000]]=false;
		for(int i=head[que[l%2000]];i;i=way[i].next)
		{
			if(dis[que[l%2000]]+way[i].v<dis[way[i].to])
			{
				dis[way[i].to]=dis[que[l%2000]]+way[i].v;
				if(!in[way[i].to])
				{
					que[++r%2000]=way[i].to;
					in[way[i].to]=true;
				}
			}
		}
	}
	printf("%d",dis[t]>1000000000?-1:dis[t]);
	return 0;
}

