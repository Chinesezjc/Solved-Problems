//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ans[101],tmp;
int find(int now)
{
	int l=1,r=1000000,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		cout<<"guess "<<now<<' '<<mid<<endl<<flush;
		cin>>tmp;
		if(tmp==-1)
		{
			l=mid+1;
			continue;
		}
		if(tmp==0)
		{
			return mid;
		}
		if(tmp==1)
		{
			r=mid-1;
			continue;
		}
	}
	return l;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cout<<"get_num"<<endl<<flush; 
	cin>>n;
	for(int i=0;i<n;++i)
	{
		ans[i]=find(i);
	}
	cout<<"submit ";
	for(int i=0;i<n;++i)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl<<flush;
	return 0;
}

