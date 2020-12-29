//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct player{
	string name,job;
	int level,value,p;
}p[200];
int n;
bool cmp1(const player &A,const player &B)
{
	return A.value==B.value?A.p<B.p:A.value>B.value;
}
bool cmp2(const player &A,const player &B)
{
	return A.level==B.level?A.p<B.p:A.level>B.level;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>p[i].name>>p[i].job>>p[i].value>>p[i].level;
		if(p[i].job=="BangZhu")
		{
			p[i].value=INF;
		}
		if(p[i].job=="FuBangZhu")
		{
			p[i].value=INF-1;
		}
		p[i].p=i;
	}
	sort(p+1,p+1+n,cmp1);
	sort(p+1,p+2,cmp2);
	for(int i=1;i<=1;++i)
	{
		p[i].job="BangZhu";
	}
	sort(p+2,p+4,cmp2);
	for(int i=2;i<=3;++i)
	{
		p[i].job="FuBangZhu";
	}
	sort(p+4,p+6,cmp2);
	for(int i=4;i<=5;++i)
	{
		p[i].job="HuFa";
	}
	sort(p+6,p+10,cmp2);
	for(int i=6;i<=9;++i)
	{
		p[i].job="ZhangLao";
	}
	sort(p+10,p+17,cmp2);
	for(int i=10;i<=16;++i)
	{
		p[i].job="TangZhu";
	}
	sort(p+17,p+42,cmp2);
	for(int i=17;i<=41;++i)
	{
		p[i].job="JingYing";
	}
	if(n>41)
	{
		sort(p+42,p+1+n,cmp2);
		for(int i=42;i<=n;++i)
		{
			p[i].job="BangZhong";
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<p[i].name<<' '<<p[i].job<<' '<<p[i].level<<endl;
	}
	return 0;
}

