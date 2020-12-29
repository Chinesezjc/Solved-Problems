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
int ans;
double x,X,Y,t;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>x;
    x=x*PI/180;
    X+=sin(t);Y+=cos(t);
    // cout<<t<<' '<<sin(t)<<' '<<cos(t)<<endl;
    t+=x;
    ++ans;
    while(abs(X)>0.00000005||abs(Y)>0.00000005)
    {
        X+=sin(t);Y+=cos(t);
        // cout<<t<<' '<<sin(t)<<' '<<cos(t)<<endl;
        t+=x;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}