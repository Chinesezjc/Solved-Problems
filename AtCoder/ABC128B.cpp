// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    std::string a;
    int b, p;
    friend bool operator<(const node &A, const node &B)
    {
        return A.a == B.a ? A.b > B.b : A.a < B.a;
    }
} a[105];
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].a >> a[i].b, a[i].p = i;
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        std::cout << a[i].p << std::endl;
    return 0;
}