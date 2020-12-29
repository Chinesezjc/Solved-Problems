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
string num,in;
map<string,vector<int> > g;
int TMP;
string getstring(string tmp)
{
    for(int i=0;i<(int)tmp.length();++i)
    {
        if(tmp[i]=='[')
        {
            return tmp.substr(0,i);
        }
    }
    return tmp;
}
int getnumber(string tmp)
{
    for(int i=0;i<(int)tmp.length();++i)
    {
        if(isdigit(tmp[i]))
        {
            int x=tmp[i]^48;
            while(++i<(int)tmp.length()&&isdigit(tmp[i]))
            {
                x=(x<<3)+(x<<1)+(tmp[i]^48);
            }
            return x;
        }
    }
    return -1;
}
int& get(string tmp)
{
    if(isdigit(tmp[0]))
    {
        TMP=getnumber(tmp);
        return TMP;
    }
    string l=getstring(tmp);
    map<string,vector<int> > :: iterator f=g.find(l);
    if(f==g.end())
    {
        cout<<-1<<endl;
        exit(0);
    }
    int h=get(tmp.substr(l.length()+1,tmp.length()-l.length()-2));
    if(h>=(int)(f->second.size())||h<0)
    {
        cout<<-1<<endl;
        exit(0);
    }
    return f->second[h];
}
signed main()
{
    ios::sync_with_stdio(false);
    while(cin>>in)
    {
        if(in=="int")
        {
            cin>>in;
            string nxt=getstring(in);
            g[nxt].assign(get(in.substr(nxt.length()+1,in.length()-2-nxt.length())),0);
            continue;
        }
        if(in=="cout")
        {
            cin>>in;
            cout<<get(in)<<endl;
            continue;
        }
        cin>>num;
        int tmp=get(num);
        get(in)=tmp;
    }
    return 0;
}