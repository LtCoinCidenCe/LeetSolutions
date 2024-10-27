#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution1 {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long result = 0;
        for (int i = 0; i < k; i++)
        {
            int index = 0;
            int lowest = 300000;
            for (int j = 0; j < costs.size(); j++)
            {
                if (j < candidates || j >= costs.size() - candidates)
                {
                    if (costs[j] < lowest)
                    {
                        index = j;
                        lowest = costs[j];
                    }
                }
                else
                {
                    continue;
                }
            }
            result += lowest;
            costs.erase(costs.begin() + index);
        }
        return result;
    }
};

class Solution2 {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long result = 0;
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>>q;
        int left = candidates - 1;
        int right = n - candidates;
        if (left < right)
        {
            for (size_t i = 0; i < left + 1; i++)
            {
                q.emplace(costs[i], i);
            }
            for (size_t i = right; i < n; i++)
            {
                q.emplace(costs[i], i);
            }
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                q.emplace(costs[i], i);
            }
        }

        while (k!=0)
        {
            auto a = q.top();
            q.pop();
            result += a.first;
            k--;
            int pushIndex = -1;
            if (a.second <= left)
            {
                left++;
                pushIndex = left;
            }
            else if (a.second >= right)
            {
                right--;
                pushIndex = right;
            }
            if (pushIndex != -1 && left < right)
            {
                q.emplace(costs[pushIndex], pushIndex);
            }
        }
        return result;
    }
};


int q2462()
{
    Solution2 s;
    vector<int>costs{ 31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58 };
    int k = 11, candidate = 2;
    pair<int, int> a{ 3,6 }, b{ 4,5 };
    bool compare = a < b;
    long long totalCost = s.totalCost(costs, k, candidate);
    return 0;
}
