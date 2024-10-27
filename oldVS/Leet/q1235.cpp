#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>startOrder(n, 0);
        iota(startOrder.begin(), startOrder.end(), 0);
        sort(startOrder.begin(), startOrder.end(), [&](int a, int b)
            {
                return startTime[a] < startTime[b];
            });

        int result = 0;
        vector<int>stationProfit;
        for (int i = 0; i < n; i++)
        {
            int temp = profit[i];
            stationProfit.push_back(temp);
            result = max(temp, result);
        }
        // station max n, next step max n, maxProfit==result a sum of stations
        // vector<vector<int>>s(n, vector<int>()); 结果还不需要这个站点啦？
        // s[4] is a vector, at station 4, pointing to next possible stations
        for (int i = 0; i < n; i++) // startOrder[i]
        {
            int messingIndex = startOrder[i];
            int thisEnd = endTime[messingIndex];
            int followerinSO = 500009;

            int lower = i + 1;
            int u = (i + n) / 2;
            int higher = n - 1;
            while (true)
            {
                int secondStart = startTime[startOrder[u]];
                if (secondStart < thisEnd)
                {
                    if (u == higher)
                    {
                        // no bigger value
                        break;
                    }
                    lower = u + 1;
                    u = (u + 1 + higher) / 2;
                }
                else // assert secondStart >= thisEnd
                {
                    int thirdStart = startTime[startOrder[u - 1]];
                    if (thirdStart < thisEnd)
                    {
                        followerinSO = u;
                        break;
                    }
                    else
                    {
                        if (u == lower)
                        {
                            break;
                        }
                        higher = u - 1;
                        u = (lower + u) / 2;
                    }
                }
            }

            //for (int j = i + 1; j < n; j++)
            //{
            //    int secondStart = startTime[startOrder[j]];
            //    if (secondStart >= thisEnd)
            //    {
            //        followerinSO = j;
            //        break;
            //    }
            //}

            for (int j = followerinSO; j < n; j++)
            {
                int link = startOrder[j];
                //s[messingIndex].push_back(link);
                int newProfit = stationProfit[messingIndex] + profit[link];
                stationProfit[link] = max(newProfit, stationProfit[link]);
                result = max(newProfit, result);
            }
        }
        return result;
    }
};

// Solution2对力！
class Solution2 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>startOrder(n, 0);
        iota(startOrder.begin(), startOrder.end(), 0);
        sort(startOrder.begin(), startOrder.end(), [&](int a, int b)
            {
                return startTime[a] > startTime[b];
            });

        int result = 0;
        // based on startOrder not original index
        vector<int>bestSalary(n, 0);
        bestSalary[0] = profit[startOrder[0]];

        for (int i = 1; i < n; i++)
        {
            int index = startOrder[i];
            int last = bestSalary[i - 1];
            int thisSalary = profit[index];
            int thisEnd = endTime[index];
            int left = 0;
            int target = i;
            int right = i + 1;
            while (true)
            {
                if (left == right)
                {
                    break;
                }
                int u = (left + right) / 2;
                int indexU = startOrder[u];
                // someStart >= thisEnd
                int whatStart = startTime[indexU];
                if (whatStart < thisEnd) // negative
                {
                    // find bigger start
                    right = u;
                }
                else
                {
                    if (u + 1 == n)
                    {
                        break; // will never use this but binary search condition should check this
                    }
                    int secondStart = startTime[startOrder[u + 1]];
                    if (secondStart < thisEnd) // found
                    {
                        target = u;
                        break;
                    }
                    else
                    {
                        left = u + 1;
                    }
                }
            }
            int thisIncome = thisSalary + bestSalary[target];
            bestSalary[i] = max(last, thisIncome);
        }
        return bestSalary[n - 1];
    }
};

int q1235()
{
    Solution2 s;
    vector<int>startTime{ 6,15,7,11,1,3,16,2 }, endTime{ 19,18,19,16,10,8,19,8 }, profit{ 2,9,1,19,5,7,3,19 };
    int result = s.jobScheduling(startTime, endTime, profit);
    return result;
}
