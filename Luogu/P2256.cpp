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
#define INF 0x3fffffffffffffff
using namespace std;
const long double PI=acos(-1);
const long double eps=0.0000000001;
string name[20005],a,b;
int cnt,n,m,fa[20005],q;
map<string,int> id;
int find(int now)
{
    return fa[now]==now?now:fa[now]=find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>name[i];
        id[name[i]]=++cnt;
        fa[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        fa[find(id[a])]=find(id[b]);
    }
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>a>>b;
        cout<<(find(id[a])==find(id[b])?"Yes.":"No.")<<endl;
    }
    return 0;
}