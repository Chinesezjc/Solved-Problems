//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
template <class Type>
class heap
{
private:
    class node
    {
    public:
        Type val;
        int dis;
        node *fa, *lson, *rson;
        void swap()
        {
            swap(lson, rson);
        }
        bool bad() const
        {
            return lson_dis() < rson_dis();
        }
        void update()
        {
            if (bad())
                swap();
            dis = rson_dis() + 1;
        }

    private:
        int lson_dis() const { return lson ? lson->dis : -1; }
        int rson_dis() const { return rson ? rson->dis : -1; }
    };
    node *root;

public:
    bool empty() const { return root; }
    Type top() const { return root ? root->val : Type(); }
    void push(const Type &x)
    {
        if (empty())
            return (void)root = new node{x, 0, 0, 0, 0};
        
    }
    void pop()
    {
    }
    void merge(heap &x)
    {
    }
};
heap<int> h[100005];
int n, m;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int tmp;
        cin >> tmp;
        h[i].push(tmp);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x >> y;
            h[x].merge(h[y]);
            break;
        case 2:
            cin >> x;
            cout << (h[x].empty() ? h[x].top() : -1) << endl;
            h[x].pop();
            break;
        }
    }
    return 0;
}