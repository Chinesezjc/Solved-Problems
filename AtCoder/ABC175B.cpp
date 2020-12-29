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
int l[105],n,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>l[i];
    }
    sort(l+1,l+1+n);
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(l[i]==l[j])
            {
                continue;
            }
            for(int k=j+1;k<=n;++k)
            {
                if(l[j]==l[k])
                {
                    continue;
                }
                if(l[i]+l[j]>l[k])
                {
                    ++ans;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}