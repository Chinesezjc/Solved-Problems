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
int n;
vector<string> a,b;
vector<string> spin(vector<string> now)
{
    vector<string> res;
    res.assign(n+5,"");
    for(int i=0;i<(int)res.size();++i)
    {
        res[i].assign(n+5,' ');
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            res[j][n-i+1]=now[i][j];
        }
    }
    return res;
}
string ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    a.assign(n+5,"");
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]=' '+a[i]+"    ";
    }
    b.assign(n+5,"");
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        b[i]=' '+b[i]+"    ";
    }
    for(int t=1;t<=4;++t)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]=='O')
                {
                    ans+=b[i][j];
                }
            }
        }
        a=spin(a);
    }
    cout<<ans<<endl;
    return 0;
}