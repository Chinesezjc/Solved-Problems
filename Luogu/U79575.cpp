//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,t,a[4000001],cnt,i,j;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>k;
		j=n;
		while(j)
		{
			k-=n-j+1;
			if(k<=0)
			{
				k+=n-j+1;
				break;
			}
			--j;
		}
		if(k-(n-j+1)<=0)
		{
			int I=k,J=j+k-1;
			cout<<100000*(I-J)+I*I+J*J+I*J<<endl;
			continue;
		}
		i=2;
		while(i<=n)
		{
			k-=n-i+1;
			if(k<=0)
			{
				k+=n-i+1;
				break;
			}
			++i;
		}
		if(k-(n-i+1)<=0)
		{
			int I=i+k-1,J=k;
			cout<<100000*(I-J)+I*I+J*J+I*J<<endl;
			continue;
		}
	}
	return 0;
}

