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
#define MOD 20060208
#define BASE 29
using namespace std;
int n,cnt,have[26],ans;
string s[200005];
struct tree{
    int son[26],has[26],now;
    bool close;
}t[1000005];
void add(int i,int now,int u)
{
    if(now==(int)s[i].length())
    {
        return;
    }
    for(int j=0;j<26;++j)
    {
        t[u].has[j]+=have[j]>0;
    }
    --have[(int)s[i][now]];
    if(t[u].son[(int)s[i][now]])
    {
        add(i,now+1,t[u].son[(int)s[i][now]]);
    }
    else
    {
        t[++cnt].now=s[i][now];
        add(i,now+1,t[u].son[(int)s[i][now]]=cnt);
    }
}
void work(int i,int now,int u)
{
    if(now==(int)s[i].length()-1)
    {
        ans+=t[u].has[(int)s[i].back()]-1;
        return;
    }
    work(i,now+1,t[u].son[(int)s[i][now]]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    t[0].now=-1;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=0;j<<1<(int)s[i].length();++j)
        {
            swap(s[i][j],s[i][s[i].length()-j-1]);
        }
        for(int j=0;j<26;++j)
        {
            have[j]=0;
        }
        for(int j=0;j<(int)s[i].length();++j)
        {
            s[i][j]-='a';
            ++have[(int)s[i][j]];
        }
        add(i,0,0);
    }
    // cout<<cnt<<endl;
    // for(int i=0;i<=cnt;++i)
    // {
    //     cout<<t[i].now<<' '<<t[i].has[0]<<' '<<t[i].has[1]<<' '<<t[i].has[2]<<endl;
    // }
    for(int i=1;i<=n;++i)
    {
        work(i,0,0);
    }
    cout<<ans<<endl;
    return 0;
}