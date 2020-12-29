//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a[1001],b;
int n,m,len,lena[1001],ans;
bool flag;
signed main()
{
	cin>>m>>n;
	while(getchar()!='\n');
	for(int i=1;i<=m;++i)
	{
		getline(cin,a[i]);
		lena[i]=a[i].length();
	}
	while(n)
	{
		--n;
		getline(cin,b);
		len=b.length();
		for(int i=1;i<=m;++i)
		{
			if(lena[i]<len)
			{
				continue;
			}
			flag=true;
			for(int j=0;j<len;++j)
			{
				if(a[i][j]!=b[j])
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				++ans;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

