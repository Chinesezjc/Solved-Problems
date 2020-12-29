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
vector<string> ans;
string power=" ";
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    ans.push_back(" /\\ ");
    ans.push_back("/__\\");
    while(--n)
    {
        int len=ans.size();
        power=power+power;
        for(int i=0;i<len;++i)
        {
            ans.push_back(ans[i]+ans[i]);
            ans[i]=power+ans[i]+power;
        }
    }
    for(int i=0;i<(int)ans.size();++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}