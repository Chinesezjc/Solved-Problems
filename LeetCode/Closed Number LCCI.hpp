#include <vector>
class Solution
{
public:
    std::vector<int> findClosedNumbers(int num)
    {
        std::vector<int> res(2, -1);
        for (int i = 1; i != 31; ++i)
            if (num & (1 << i) && ~num & (1 << i >> 1))
            {
                res.back() = num ^ (1 << i | 1 << i >> 1);
                int cnt = 0;
                for (int j = 0; j != i; ++j)
                    if (res.back() & (1 << j))
                    {
                        ++cnt;
                        res.back() ^= 1 << j;
                    }
                for (int j = i; j-- && cnt--;)
                    res.back() |= 1 << j;
                break;
            }
        for (int i = 1; i != 31; ++i)
            if (~num & (1 << i) && num & (1 << i >> 1))
            {
                res.front() = num ^ (1 << i | 1 << i >> 1);
                int cnt = 0;
                for (int j = 0; j != i; ++j)
                    if (res.front() & (1 << j))
                    {
                        ++cnt;
                        res.front() ^= 1 << j;
                    }
                for (int j = 0; cnt--; ++j)
                    res.front() |= 1 << j;
                break;
            }
        return res;
    }
};