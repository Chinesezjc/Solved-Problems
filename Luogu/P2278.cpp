// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    int id, time, left, heavy;
    friend bool operator<(const node &A, const node &B)
    {
        return A.heavy == B.heavy ? A.time > B.time : A.heavy < B.heavy;
    }
} tmp, doing;
long long cur;
std::priority_queue<node> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    doing.id = -1;
    while (std::cin >> tmp.id >> tmp.time >> tmp.left >> tmp.heavy)
    {
        while (cur < tmp.time && ~doing.id)
        {
            int run = std::min(doing.left, tmp.time - static_cast<int>(cur));
            doing.left -= run;
            cur += run;
            if (doing.left == 0)
            {
                std::cout << doing.id << ' ' << cur << std::endl;
                if (!que.empty())
                {
                    doing = que.top();
                    que.pop();
                }
                else
                {
                    doing.id = -1;
                    break;
                }
            }
        }
        cur = tmp.time;
        if (!~doing.id)
            doing = tmp;
        else if (doing < tmp)
            que.push(doing), doing = tmp;
        else
            que.push(tmp);
    }
    while (~doing.id)
    {
        int run = doing.left;
        doing.left -= run;
        cur += run;
        if (doing.left == 0)
        {
            std::cout << doing.id << ' ' << cur << std::endl;
            if (!que.empty())
            {
                doing = que.top();
                que.pop();
            }
            else
                break;
        }
    }
    return 0;
}