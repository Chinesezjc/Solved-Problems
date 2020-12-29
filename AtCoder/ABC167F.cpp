//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,now,gcnt,ncnt,bcnt;
string a;
struct S{
	int least,give;
}s,good[1000001],normal[1000001],bad[1000001];
bool gcmp(const S &A,const S &B)
{
	return A.least<B.least;
}
bool bcmp(const S &A,const S &B)
{
	return A.least>B.least;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		int len=a.length();
		s.give=s.least=0;
		for(int j=0;j<len;++j)
		{
			if(a[j]=='(')
			{
				++s.give;
			}
			else
			{
				--s.give;
				s.least=max(s.least,-s.give);
			}
		}
		if(s.give>0)
		{
			good[++gcnt]=s;
		}
		if(s.give==0)
		{
			normal[++ncnt]=s;
		}
		if(s.give<0)
		{
			bad[++bcnt]=s;
		}
	}
	sort(good+1,good+1+gcnt,gcmp);
	sort(bad+1,bad+1+bcnt,bcmp);
	for(int i=1;i<=gcnt;++i)
	{
		if(now<good[i].least)
		{
			cout<<"No"<<endl;
			return 0;
		}
		now+=good[i].give;
	}
	for(int i=1;i<=ncnt;++i)
	{
		if(now<normal[i].least)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(int i=1;i<=bcnt;++i)
	{
		if(now<bad[i].least)
		{
			cout<<"No"<<endl;
			return 0;
		}
		now+=bad[i].give;
	}
	if(now!=0)
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
	}
	return 0;
}

