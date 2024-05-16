#include<vector>
#include<algorithm>
#include<numeric>
#include<ranges>
using namespace std;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        // [starti, endi, durationi]
        int n = tasks.size();
        vector<int>endTimeOrder(n, 0);
        iota(endTimeOrder.begin(), endTimeOrder.end(), 0);
        ranges::sort(endTimeOrder.begin(), endTimeOrder.end(), [&](int a, int b) {return tasks[a][1] < tasks[b][1]; });

        int result = 0;
        vector<bool>turnOn(tasks[endTimeOrder[n - 1]][1] + 1, false);
        for (int i = 0; i < n; i++)
        {
            int index = endTimeOrder[i];
            vector<int>& finishTask = tasks[index];
            // 要确保finishTask完成
            // 尽量选择后方seconds
            // 寻交集 == finishTask[0] <= 某结束时间 <= finishTask[1]     后面的等着沾前面的便宜
            // 不寻交集了，反正看前面有没有开机就完了
            int targetValue = finishTask[0];
            //int someIndex = upper_bound(endTimeOrder.begin(), endTimeOrder.begin() + i, targetValue, [&](int value, int element) {return value < tasks[element][1]; }) - endTimeOrder.begin();
            //for (int j = someIndex; j < i; j++)
            //{
            //    // 看沾了多少光
            //}
            int wentOn = 0;
            for (int j = targetValue; j <= finishTask[1]; j++)
            {
                if (turnOn[j]==true)
                {
                    wentOn++;
                }
            }
            if (wentOn < finishTask[2])
            {
                int needed = finishTask[2] - wentOn;
                for (int j = finishTask[1]; needed > 0; j--)
                {
                    if (turnOn[j] == false)
                    {
                        turnOn[j] = true;
                        needed--;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

int q2589()
{
    Solution s;
    int result = 0;
    vector<vector<int>>tasks{ vector<int>{2,3,1},vector<int>{4,5,1},vector<int>{1,5,2} };
    result = s.findMinimumTime(tasks);
    return result;
}
