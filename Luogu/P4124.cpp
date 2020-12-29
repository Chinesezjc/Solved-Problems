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
string a,b;
bool check(string now)
{
    bool _4=false,_8=false;
    for(int i=0;i<11;++i)
    {
        _4|=now[i]=='4';
        _8|=now[i]=='8';
    }
    if(_4&&_8)
    {
        return false;
    }
    for(int i=0;i<9;++i)
    {
        if(now[i]==now[i+1]&&now[i+1]==now[i+2])
        {
            return true;
        }
    }
    return false;
}
int dp[15][2][2][2][2][15][15],num[15];
int dfs(int now,bool up,bool _4,bool _8,bool three,int lst2,int lst)
{
    if(_4&&_8)
    {
        return 0;
    }
    if(now>11)
    {
        return three;
    }
    if(~dp[now][up][_4][_8][three][lst2][lst])
    {
        return dp[now][up][_4][_8][three][lst2][lst];
    }
    int tmp=0,lim=up?num[now]:9;
    for(int i=0;i<=lim;++i)
    {
        tmp+=dfs(now+1,up&&i==num[now],_4||i==4,_8||i==8,three||(lst2==lst&&lst==i),lst,i);
    }
    return dp[now][up][_4][_8][three][lst2][lst]=tmp;
}
int work(string now)
{
    memset(dp,0xff,sizeof(dp));
    for(int i=1;i<=11;++i)
    {
        num[i]=now[i-1]^'0';
    }
    int tmp=0;
    for(int i=1;i<=num[1];++i)
    {
        tmp+=dfs(2,i==num[1],i==4,i==8,false,0,i);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    cout<<work(b)-work(a)+check(a)<<endl;
    return 0;
}