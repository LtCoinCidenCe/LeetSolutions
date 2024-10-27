#include<vector>
#include<list>
#include<queue>
using namespace std;

class SolutionGG {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        size_t n = nums.size();
        size_t quota = n - k;

        vector<int>result(k, INT_MAX);
        int firstSmall = INT_MAX;
        size_t firstIndex = 0;
        for (size_t i = 0; i < n - k + 1; i++)
        {
            if (nums[i] < firstSmall)
            {
                firstSmall = nums[i];
                firstIndex = i;
            }
        }
        result[0] = firstSmall;
        quota = min(n - firstIndex - k, quota);

        list<int>q;
        size_t resultIndex = 1;
        for (size_t i = firstIndex + 1; i < n; i++)
        {
            int a = nums[i];

            size_t j = 0;
            list<int>::iterator iter;
            if (quota != 0)
            {
                for (list<int>::iterator i = q.begin(); i != q.end(); i++)
                {
                    if (a < *i)
                    {
                        iter = i;
                        break;
                    }
                    j++;
                }
            }

            if (j != q.size())
            {
                int back = q.size() - j;
                quota -= back;
                resultIndex -= back;
                q.erase(iter);
                q.push_back(a);
                while (q.size() > quota)
                {
                    q.pop_front();
                }
            }
            else
            {
                q.push_back(a);
                while (q.size() > quota)
                {
                    q.pop_front();
                }
            }

            if (resultIndex < k)
            {
                result[resultIndex] = a;
                resultIndex++;
            }
            else
            {
                break;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result;
        for (int i = 0; i < n; i++)
        {
            while (!result.empty() && n - i + result.size() > k && result.back() > nums[i])
            {
                result.pop_back();
            }

            result.push_back(nums[i]);
        }
        result.resize(k);
        return result;
    }
};


int q1673()
{
    Solution s;
    vector<int>nums{ 57,3,87,51,93,57,68,47,73,1,32,13,11,55,46,76,75,80,53,39,37,18 };
    int k = 16;
    vector<int>result;
    result = s.mostCompetitive(nums, k);
    return 0;
}
