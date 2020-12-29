//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,l,b[6],cho,ans,cnt,cht;
struct NUM{
	int num,p;
	bool operator < (const NUM &TMP)const
	{
		return num==TMP.num?p<TMP.p:num<TMP.num;
	}
}a[1000001];
int find(int x,int v)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid].num<v)
		{
			l=mid+1;
			continue;
		}
		if(a[mid].num>v)
		{
			r=mid-1;
			continue;
		}
		if(a[mid].p<=x)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return a[l].p>x&&a[l].num==v?a[l].p:-1;
}
bool check()
{
	int A=0,C=0;
	while(A<l&&C<l)
	{
		++A;
		++C;
		while(A<l&&!(ans&(1<<(l-A))))
		{
			++A;
		}
		while(C<l&&!(cho&(1<<(l-C))))
		{
			++C;
		}
		if(b[A]!=b[C])
		{
			return b[A]>b[C];
		}
	}
	return false;
}
void dfs(int now,int i)
{
	if(i>l)
	{
		if(cht>cnt||(cht==cnt&&check()))
		{
			cnt=cht;
			ans=cho;
		}
		return;
	}
	int nxt=find(now,b[i]);
	if(nxt!=-1)
	{
		++cht;
		cho^=1<<(l-i);
		dfs(nxt,i+1);
		cho^=1<<(l-i);
		--cht;
	}
	dfs(now,i+1);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].num;
		a[i].p=i;
	}
	sort(a+1,a+1+n);
	cin>>m;
	while(m)
	{
		--m;
		cin>>l;
		for(int i=1;i<=l;++i)
		{
			cin>>b[i];
		}
		cnt=ans=0;
		dfs(0,1);
		cout<<cnt;
		for(int i=1;i<=l;++i)
		{
			if(ans&(1<<(l-i)))
			{
				cout<<' '<<b[i];
			}
		}
		cout<<endl;
	}
	return 0;
}

