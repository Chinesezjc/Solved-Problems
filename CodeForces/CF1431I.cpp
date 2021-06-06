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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, q, cnt, root = cnt++, ans[250005], head[250005], lst[250005];
std::string s[250005];
struct node
{
    int son[26];
    node() { memset(son, -1, sizeof(son)); }
} trie[500005];
void add(int now, std::string &str, int pos)
{
    if (pos == m)
        return;
    if (~trie[now].son[str[pos] - 'a'])
        add(trie[now].son[str[pos] - 'a'], str, pos + 1);
    else
        add(trie[now].son[str[pos] - 'a'] = cnt++, str, pos + 1);
}
void merge(int A, int B)
{
    for (int i = 0; i != 26; ++i)
        if (~trie[B].son[i])
        {
            if (~trie[A].son[i])
                merge(trie[A].son[i], trie[B].son[i]);
            else
                trie[A].son[i] = trie[B].son[i];
        }
}
int merge_son(int now)
{
    int x = 0;
    while (x != 26 && !~trie[now].son[x])
        ++x;
    for (int i = x + 1; i != 26; ++i)
        if (~trie[now].son[i])
            merge(trie[now].son[x], trie[now].son[i]);
    return trie[now].son[x];
}
int pd(int now, std::string &str, int pos)
{
    if (pos != m && ~trie[now].son[str[pos] - 'a'])
        return pd(trie[now].son[str[pos] - 'a'], str, pos + 1);
    else
        return pos;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> s[i];
        add(root, s[i], 0);
    }
    memset(head, -1, sizeof(head));
    for (int i = 0; i != q; ++i)
    {
        std::cin >> s[i];
        lst[i] = head[0];
        head[0] = i;
    }
    for (int i = 0; i != m; ++i)
    {
        for (int j = head[i], nxt; ~j; j = nxt)
        {
            nxt = lst[j];
            ++ans[j];
            int tmp = pd(root, s[j], i);
            if (tmp == i)
                ans[j] = 0;
            else
            {
                lst[j] = head[tmp];
                head[tmp] = j;
            }
        }
        root = merge_son(root);
    }
    for (int i = 0; i != q; ++i)
        std::cout << ans[i] - 1 << std::endl;
    return 0;
}