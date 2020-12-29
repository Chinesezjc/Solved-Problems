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
string s,t;
int ans=INF,tmp;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>s>>t;
    for(int i=0;i+(int)t.length()-1<(int)s.length();++i)
    {
        tmp=0;
        for(int j=0;j<(int)t.length();++j)
        {
            if(s[i+j]!=t[j])
            {
                ++tmp;
            }
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}