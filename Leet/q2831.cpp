#include<vector>
#include<unordered_map>
using namespace std;

// bar[start,end,cost]
// barvector
// bartype [num,barvector]
class Solution {
    // this is corrent but not efficient
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int result = 0;
        unordered_map<int, vector<vector<int>>>u;
        u[nums[0]] = vector<vector<int>>{ vector<int>{0, 0, 0} };
        for (int i = 1; i < n; i++)
        {
            auto& prev = u[nums[i - 1]];
            int temp = prev.size();
            if (nums[i] == nums[i - 1])
            {
                prev[temp - 1][1]++;
            }
            else
            {
                // 计分
                int longest = 0; int bank = k;
                for (int j = 0; ; j++)
                {
                    if (bank < 0)
                    {
                        break;
                    }
                    if (temp - 1 - j < 0)
                    {
                        break;
                    }
                    auto theStartEnd = prev[temp - 1 - j];
                    int plus = theStartEnd[1] - theStartEnd[0] + 1;
                    longest += plus;
                    bank -= theStartEnd[2];
                }
                result = max(result, longest);
                temp = u[nums[i]].size();
                int cost = 0;
                if (!u[nums[i]].empty())
                {
                    auto& cur = u[nums[i]];
                    auto& last = cur[temp - 1];
                    cost = i - last[1] - 1;
                }
                u[nums[i]].emplace_back(vector<int>{i, i, cost});
            }
        }

        // 最后个计分
        int temp = u[nums[n - 1]].size();
        int bank = k;
        auto& prev = u[nums[n - 1]];
        int longest = 0;
        for (int j = 0; ; j++)
        {
            if (bank < 0)
            {
                break;
            }
            if (temp - 1 - j < 0)
            {
                break;
            }
            auto theStartEnd = prev[temp - 1 - j];
            int plus = theStartEnd[1] - theStartEnd[0] + 1;
            longest += plus;
            bank -= theStartEnd[2];
        }
        result = max(result, longest);
        return result;
    }
};

class Solution2 {
    // doesn't need to hide
    // You shouldn't delete more if you want to have highest number
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        unordered_map<int, int>numCntInWindow;
        int i = 0, j = 0;
        while (true)
        {
            if (j >= n)
            {
                break;
            }
            numCntInWindow[nums[j]]++;
            while (j - i + 1 - numCntInWindow[nums[i]] > k)
            {
                // right shift
                numCntInWindow[nums[i]]--;
                i++;
            }
            result = max(result, numCntInWindow[nums[j]]);
            j++;
        }
        return result;
    }
};

int q2831()
{
    Solution2 s;
    vector<int>vs{ 1,3,2,3,1,3 };
    int result = s.longestEqualSubarray(vs, 3);
    return result;
}
