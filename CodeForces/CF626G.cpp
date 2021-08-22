// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define double long double
const double eps = 1e-12;
int n, t, q, l[200005], p[200005], x[200005];
double ans;
std::priority_queue<std::pair<double, int>,
                    std::vector<std::pair<double, int>>,
                    std::less<std::pair<double, int>>>
    unadd;
std::priority_queue<std::pair<double, int>,
                    std::vector<std::pair<double, int>>,
                    std::greater<std::pair<double, int>>>
    added;
double calc(int num) { return ((x[num] + 1.0) / (l[num] + x[num] + 1) - 1.0 * x[num] / (l[num] + x[num])) * p[num]; }
double calc_(int num) { return (1.0 * x[num] / (l[num] + x[num]) - (x[num] - 1.0) / (l[num] + x[num] - 1)) * p[num]; }
void push(int num)
{
    ans += calc(num);
    added.push({calc(num), num});
    ++x[num];
    --t;
    if (x[num] < l[num])
        unadd.push({calc(num), num});
}
void pop(int num)
{
    ans -= calc_(num);
    unadd.push({calc_(num), num});
    --x[num];
    ++t;
    if (x[num] > 0)
        added.push({calc_(num), num});
}
bool neq(double A, double B) { return fabs(A - B) > eps; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t >> q;
    std::cout << std::fixed << std::setprecision(9);
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> l[i];
    for (int i = 1; i <= n; ++i)
        unadd.push({calc(i), i});
    for (int i = 1; i <= q; ++i)
    {
        static int opt, num;
        std::cin >> opt >> num;
        switch (opt)
        {
        case 1:
            ans -= 1.0 * x[num] / (l[num] + x[num]) * p[num];
            ++l[num];
            ans += 1.0 * x[num] / (l[num] + x[num]) * p[num];
            break;
        case 2:
            ans -= 1.0 * x[num] / (l[num] + x[num]) * p[num];
            --l[num];
            if (x[num] > l[num])
                --x[num], ++t;
            ans += 1.0 * x[num] / (l[num] + x[num]) * p[num];
            break;
        }
        if (x[num] < l[num])
            unadd.push({calc(num), num});
        if (x[num] > 0)
            added.push({calc_(num), num});
        while (!unadd.empty() && neq(unadd.top().first, calc(unadd.top().second)))
            unadd.pop();
        while (t && !unadd.empty())
        {
            std::pair<double, int> now = unadd.top();
            unadd.pop();
            if (neq(now.first, calc(now.second)))
                continue;
            push(now.second);
        }
        while (!unadd.empty() && !added.empty() && added.top().first < unadd.top().first)
        {
            std::pair<double, int> now = added.top();
            added.pop();
            if (neq(now.first, calc_(now.second)))
                continue;
            pop(now.second);
            while (t && !unadd.empty())
            {
                std::pair<double, int> now = unadd.top();
                unadd.pop();
                if (neq(now.first, calc(now.second)))
                    continue;
                push(now.second);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}