#include <vector>
class Solution
{
public:
    int pivotIndex(std::vector<int> &nums)
    {
        std::vector<int> sum;
        sum.push_back(0);
        for (int i = 0; i != nums.size(); ++i)
        {
            sum.push_back(sum.back() + nums[i]);
        }
        for (int i = 0; i != nums.size(); ++i)
        {
            if (sum[i] == sum[nums.size()] - sum[i + 1])
            {
                return i;
            }
        }
        return -1;
    }
};