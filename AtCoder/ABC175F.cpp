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
int n,ans=INF;
struct L{
    int v;
    string s,e;
    bool operator < (const L &TMP)const
    {
        return v<TMP.v;
    }
}a[55];
struct F{
    int used;
    string g;
    bool operator < (const F &TMP)const
    {
        return used>TMP.used;
    }
};
priority_queue<F>dl;
string work(string now)
{
    for(int i=0;i<(int)now.length()>>1;++i)
    {
        swap(now[i],now[now.length()-i-1]);
    }
    return now;
}
bool good(string now,string x)
{
    for(int i=0;i<(int)x.length();++i)
    {
        if(now[i]!=x[i])
        {
            return false;
        }
    }
    return true;
}
bool allhigh(string now)
{
    for(int i=1;i<=n;++i)
    {
        if(now.length()<a[i].e.length()&&now==a[i].e.substr(0,now.length()))
        {
            return false;
        }
    }
    return true;
}
bool can(F now)
{
    if(allhigh(now.g))
    {
        for(int i=1;i<=n;++i)
        {
            if(now.used+a[i].v<ans&&now.g.substr(0,a[i].e.length())==a[i].e)
            {
                return true;
            }
        }
        return false;
    }
    for(int i=1;i<=n;++i)
    {
        if(now.used+a[i].v>=ans)
        {
            continue;
        }
        int len=min(a[i].e.length(),now.g.length());
        bool flag=true;
        for(int j=0;j<len;++j)
        {
            if(now.g[j]!=a[i].e[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            return true;
        }
    }
    return false;
}
bool all(string now)
{
    for(int i=0;i<(int)now.length()>>1;++i)
    {
        if(now[i]!=now[now.length()-1-i])
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].s>>a[i].v;
        a[i].e=work(a[i].s);
    }
    sort(a+1,a+1+n);
    dl.push((F){0,""});
    while(!dl.empty()&&dl.top().used<ans)
    {
        F now=dl.top();
        dl.pop();
        for(int i=1;i<=n;++i)
        {
            if(all(now.g+a[i].s))
            {
                ans=min(now.used+a[i].v,ans);
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(good(now.g,a[i].e)&&can((F){now.used+a[i].v,now.g.substr(a[i].e.length(),now.g.length()-a[i].e.length())}))
            {
                dl.push((F){now.used+a[i].v,now.g.substr(a[i].e.length(),now.g.length()-a[i].e.length())});
            }
        }
        if(allhigh(now.g))
        {
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            if(can((F){now.used+a[i].v,now.g+a[i].s}))
            {
                dl.push((F){now.used+a[i].v,now.g+a[i].s});
            }
        }
    }
    cout<<(ans==INF?-1:ans)<<endl;
    return 0;
}