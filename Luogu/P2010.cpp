//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int monthdays[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int ans;
string s,e,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s>>e;
	for(int i=1;i<=12;++i)
	{
		for(int j=1;j<=monthdays[i];++j)
		{
			c="";
			c+=j%10+'0';
			c+=j/10+'0';
			c+=i%10+'0';
			c+=i/10+'0';
			c+=i/10+'0';
			c+=i%10+'0';
			c+=j/10+'0';
			c+=j%10+'0';
			if(s<=c&&c<=e)
			{
				++ans;
			}
		}
	}
	cout<<ans;
	return 0;
}

