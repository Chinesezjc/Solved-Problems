//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,ans,used,start;
struct student{
	int p,q;
	bool operator < (const student &TMP)const
	{
		return q==TMP.q?p<TMP.p:q<TMP.q;
	}
}s[100001];
bool cmp(const student &A,const student &B)
{
	return A.p<B.p;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i].q;
		s[i].p=i;
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;++i)
	{
		s[i].q-=used;
		int tmp=min((m-ans)/(n-i+1),s[i].q);
		ans+=tmp*(n-i+1);
		s[i].q-=tmp;
		used+=tmp;
//		cout<<s[i].q<<' '<<used<<endl;
		if(s[i].q>0)
		{
			for(int j=i+1;j<=n;++j)
			{
				s[j].q-=used;
			}
			sort(s+1,s+1+n,cmp);
			for(int j=1;ans<m;++j)
			{
				if(s[j].q>0)
				{
					--s[j].q;
					++ans;
					start=j;
				}
			}
			for(int j=start+1;j<=n;++j)
			{
				if(s[j].q>0)
				{
					cout<<s[j].p<<' ';
				}
			}
			for(int j=1;j<=start;++j)
			{
				if(s[j].q>0)
				{
					cout<<s[j].p<<' ';
				}
			}
			return 0;
		}
	}
	if(ans==m)
	{
		cout<<endl;
		return 0;
	}
	cout<<-1;
	return 0;
}

