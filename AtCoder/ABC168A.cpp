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
const char l[10]={'p','p','h','b','h','h','p','h','p','h'};
int n;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	cout<<l[n%10]<<"on"<<endl;
	return 0;
}

