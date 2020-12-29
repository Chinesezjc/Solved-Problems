//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define INF 0x3fffffff
using namespace std;
int m,n,ans=INF;
long long sum[62],s,l,r;
struct person{
	int k,can[7];
	long long d;
	bool operator < (const person &A)const
	{
		return k>A.k;
	}
}p[62];
struct S{
	int now,cho,gu;
	long long D;
	bool no;
	void rate()
	{
		int l=0;
		for(int i=0;i<n;++i)
		{
			if(!(D&1ll<<i))
			{
				++l;
			}
		}
		for(int i=now;l>0&&i<=m;++i)
		{
			l-=p[i].k;
			++gu;
		}
		if(l>0)
		{
			no=true;
			return;
		}
		gu+=cho;
	}
	bool operator < (const S &A)const
	{
		return gu>A.gu;
	}
};
priority_queue <S> que;
void bfs(int now,int cho,long long D)
{
	if(cho>=ans||(D|sum[now])!=s)
	{
		return;
	}
	if(D==s)
	{
		ans=cho;
		cout<<ans<<endl;
		exit(0);
		return;
	}
	if(cho+1==ans)
	{
		return;
	}
	while(now<=m)
	{
		long long nexD=D|p[now].d;
		if(nexD!=D)
		{
			S tmp=S{now+1,cho+1,0,nexD};
			tmp.rate();
			if(!tmp.no)
			{
				que.push(tmp);
			}
		}
		++now;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	srand(114514);
	cin>>n>>m;
	s=(1ll<<n)-1;
	for(int i=1;i<=m;++i)
	{
		cin>>p[i].k;
		for(int j=1;j<=p[i].k;++j)
		{
			cin>>p[i].can[j];
			p[i].d|=1ll<<(p[i].can[j]-1);
		}
	}
	sort(p+1,p+1+m);
	for(int i=m;i>0;--i)
	{
		sum[i]=sum[i+1]|p[i].d;
	}
	S tmp=S{1,0,0};
	tmp.rate();
	if(!tmp.no)
	{
		que.push(tmp);
	}
	while(!que.empty())
	{
		S TMP=que.top();
		que.pop();
		bfs(TMP.now,TMP.cho,TMP.D);
	}
	cout<<ans<<endl;
	return 0;
}
