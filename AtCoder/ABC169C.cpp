//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a;
string b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	cout<<a*((b[0]-'0')*100+(b[2]-'0')*10+(b[3]-'0'))/100<<endl;
	return 0;
}

