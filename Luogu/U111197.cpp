//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a;
	for(int i=0;i<=32;++i)
	{
		if((a&(1<<i))&&(!(a&(1<<(i+1)))))
		{
			a^=1<<i;
			a^=1<<(i+1);
			bool flag=true;
			while(flag)
			{
				flag=false;
				for(int j=i-1;j>0;--j)
				{
					if((a&(1<<j))&&(!(a&(1<<(j-1)))))
					{
						a^=1<<j;
						a^=1<<(j-1);
						flag=true;
					}
				}
			}
			break;
		}
	}
	cout<<a<<endl;
	return 0;
}

