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
int ans,len;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    s=' '+s;
    for(int i=1;i<=3;++i)
    {
        if(s[i]=='S')
        {
            len=0;
        }
        else
        {
            ++len;
            ans=max(ans,len);
        }
    }
    cout<<ans<<endl;
    return 0;
}