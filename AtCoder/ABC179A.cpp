//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    if(s.back()=='s')
    {
        cout<<s+"es"<<endl;
    }
    else
    {
        cout<<s+'s'<<endl;
    }
    return 0;
}