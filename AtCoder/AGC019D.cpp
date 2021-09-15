// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string A, B;
struct node
{
    int l, r, p;
    node(int x) : l(0), r(0), p(x) {}
};
std::vector<node> p;
int ans = INT_MAX, n;
void work()
{
    p.clear();
    for (int i = 0; i != n; ++i)
    {
        node tmp(i);
        while (B[(i - tmp.l + n) % n] != '1')
            ++tmp.l;
        while (B[(i + tmp.r + n) % n] != '1')
            ++tmp.r;
        p.push_back(tmp);
    }
    std::sort(p.begin(), p.end(), [&](const node &A, const node &B)
              { return A.l > B.l; });
    for (int i = 0; i != n; ++i)
    {
        int tmp = 0;
        for (int j = 0; j != n; ++j)
            tmp += A[j] != B[(j - i + n) % n];
        for (int j = n, k = 0, r = 0; j-- != i;)
        {
            while (k != n && p[k].l > j)
                if (A[p[k].p] != B[(p[k].p - i + n) % n])
                    r = std::max(p[k++].r, r);
                else
                    ++k;
            ans = std::min(ans, tmp + r + r + j + j - i);
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B;
    if (A == B)
        return std::cout << 0 << std::endl, 0;
    if (B.find('1') == std::string::npos)
        return std::cout << -1 << std::endl, 0;
    n = A.size();
    work();
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    work();
    std::cout << ans << std::endl;
    return 0;
}