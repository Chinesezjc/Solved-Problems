//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int k;
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>k>>s;
	if(k>=s.length())
	{
		cout<<s<<endl;
	}
	else
	{
		for(int i=0;i<k;++i)
		{
			cout<<s[i];
		}
		cout<<"..."<<endl;
	}
	return 0;
}

