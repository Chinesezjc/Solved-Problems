//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int m,n,pos[5001],a[302][5001],l,r,now,ans;
struct CHO{
	int p,cho;
}cho[302];
bool cmp(const CHO &A,const CHO &B)
{
	return A.cho<B.cho;
}
void s()
{
	sort(cho+1,cho+1+m,cmp);
	int tmp=0;
	for(int i=1;i<=m&&cho[i].cho!=r;++i)
	{
		tmp+=a[cho[i].p][cho[i].cho]-a[cho[i].p][r];
		if(cho[i].cho!=cho[i+1].cho&&pos[cho[i].cho]-pos[l]>=tmp)
		{
			l=cho[i+1].cho;
			for(int j=1;j<=i;++j)
			{
				now-=a[cho[i].p][cho[i].cho];
				cho[i].cho=r;
				now+=a[cho[i].p][cho[i].cho];
			}
			s();
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>pos[i];
	}
	for(int i=1;i<=m;++i)
	{
		cho[i].p=i;
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
		}
	}
	while(r<n)
	{
		++r;
		for(int i=1;i<=m;++i)
		{
			if(a[cho[i].p][cho[i].cho]<a[cho[i].p][r])
			{
				now-=a[cho[i].p][cho[i].cho];
				cho[i].cho=r;
				now+=a[cho[i].p][cho[i].cho];
			}
		}
		l=INF;
		for(int i=1;i<=m;++i)
		{
			l=min(l,cho[i].cho);
		}
		s();
		ans=max(ans,now-pos[r]+pos[l]);
//		cout<<l<<' '<<r;
//		for(int i=1;i<=m;++i)
//		{
//			cout<<"  "<<cho[i].cho;
//		}
//		cout<<"   "<<now<<endl;
	}
	cout<<ans;
	return 0;
}

