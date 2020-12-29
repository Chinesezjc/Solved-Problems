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
int n,m,a[20],b[20];
bool s[20];
bool dfs(int now,int cho)
{
    if(cho==n)
    {
        if(now==a[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for(int i=3;i<=m+2;++i)
    {
        if(s[i])
        {
            continue;
        }
        s[i]=true;
        if(a[i]==now&&dfs(b[i],cho+1))
        {
            s[i]=false;
            return true;
        }
        if(b[i]==now&&dfs(a[i],cho+1))
        {
            s[i]=false;
            return true;
        }        
        s[i]=false;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=m+2;++i)
        {
            cin>>a[i]>>b[i];
        }
        if(dfs(b[1],0))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}