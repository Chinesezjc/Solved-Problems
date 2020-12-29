//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int S,x,y,k,n,p,t;
bool isnotp[1500001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>S>>x>>y>>k;
		n=sqrt(y);
		fill(isnotp,isnotp+y-x+1,false);
		for(int i=2;i<=n;++i)
		{
			for(int j=max((x-1)/i*i+i,i<<1);j<=y;j+=i)
			{
				isnotp[j-x]=true;
			}
		}
		p=-1;
		for(int i=max(x,2ll),now=0;i<=y;++i)
		{
			if(!isnotp[i-x])
			{
				++now;
				if(now==k)
				{
					p=i;
					break;
				}
			}
		}
		if(p==-1)
		{
			cout<<"ERR"<<endl;
		}
		else
		{
			cout<<S/p%p<<endl;
		}
	}
	return 0;
}

