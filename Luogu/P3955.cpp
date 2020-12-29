//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[1001];
string book[1001],q[1001];
bool cmp(const string &A,const string &B)
{
	return A.length()==B.length()?A<B:A.length()<B.length();
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>book[i];
	}
	sort(book+1,book+1+n,cmp);
	for(int i=1;i<=m;++i)
	{
		cin>>a[i]>>q[i];
		bool flag=true;
		for(int j=1;j<=n;++j)
		{
			if(book[j].find(q[i],book[j].length()-a[i])!=string::npos)
			{
				cout<<book[j]<<endl;
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}

