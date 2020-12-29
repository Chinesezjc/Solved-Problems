//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
#define AKIOI 1
#define xyhisstupid 2
#define tooeasy 3
using namespace std;
int n,m,is[500001];
string tmp,ti[500001],name[500001];
bool back[500001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>tmp;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>tmp;
		if(tmp=="withdraw")
		{
			cin>>tmp;
			cin>>tmp;
			for(int j=i-1;j>=max(i-5,1ll);--j)
			{
				if(tmp==name[j]&&!back[j])
				{
					back[j]=true;
					break;
				}
			}
			--i;
			--m;
			continue;
		}
		if(tmp=="xyh")
		{
			--m;
			--i;
			getline(cin,tmp);
			continue;
		}
		name[i]=tmp;
		cin>>tmp;
		cin>>tmp;
		if(tmp=="xyh")
		{
			cin>>tmp;
			if(tmp=="isstupid")
			{
				is[i]=xyhisstupid;
				continue;
			}
			else
			{
				--m;
				--i;
				continue;
			}
		}
		if(tmp==name[i])
		{
			cin>>tmp;
			if(tmp=="AKIOI")
			{
				is[i]=AKIOI;
				continue;
			}
			else
			{
				--m;
				--i;
				continue;
			}
		}
		ti[i]=tmp;
		cin>>tmp;
		if(tmp=="AKIOI"||tmp=="isstupid")
		{
			--i;
			--m;
			continue;
		}
		cin>>tmp;
		cin>>tmp;
		if(tmp=="easy")
		{
			is[i]=tooeasy;
			continue;
		}
		else
		{
			--m;
			--i;
			continue;
		}
	}
	cout<<"["<<m<<" lines automatic capture]:"<<endl;
	for(int i=1;i<=m;++i)
	{
		if(back[i])
		{
			cout<<"Failed to capture (";
		}
		cout<<name[i]<<" : ";
		if(is[i]==AKIOI)
		{
			cout<<name[i]<<" AKIOI";
		}
		if(is[i]==xyhisstupid)
		{
			cout<<"xyh isstupid";
		}
		if(is[i]==tooeasy)
		{
			cout<<ti[i]<<" is too easy";
		}
		if(back[i])
		{
			cout<<")";
		}
		cout<<endl;
	}
	return 0;
}

