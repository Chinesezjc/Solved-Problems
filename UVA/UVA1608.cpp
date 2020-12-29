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
int t,n,a[200005],appear[200005],lst[200005],nxt[200005];
bool ans,flag;
map<int,int> g;
bool work(int l,int r)
{
    if(l>=r)
    {
        return true;
    }
    int L=l,R=r;
    while(L<R)
    {
        ++L;
        if(lst[L]<l&&nxt[L]>r&&(work(l,L-1)&&work(L+1,r)))
        {
            return true;
        }
        --R;
        if(lst[R]<l&&nxt[R]>r&&(work(l,R-1)&&work(R+1,r)))
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=false;
        g.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(g[a[i]]==0)
            {
                g[a[i]]=i;
                a[i]=i;
                lst[i]=0;
                nxt[i]=INF;
            }
            else
            {
                lst[i]=g[a[i]];
                nxt[g[a[i]]]=i;
                g[a[i]]=i;
                a[i]=a[lst[i]];
                nxt[i]=INF;
            }
        }
        cout<<(work(1,n)?"non-boring":"boring")<<endl;
    }
    return 0;
}