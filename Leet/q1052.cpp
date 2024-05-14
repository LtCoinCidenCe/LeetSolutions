#include<vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int bestGain = 0;
        int bestIndex = 0;
        int noChange = 0;
        int n = customers.size();
        vector<int>singleGain;
        int tolerenceGain = 0;
        for (int i = 0; i < n; i++)
        {
            // 建立获益数组和摆烂总客户数
            if (grumpy[i] == 1)
            {
                singleGain.push_back(customers[i]);
            }
            else
            {
                noChange += customers[i];
                singleGain.push_back(0);
            }
            // 建立获益数组和摆烂总客户数

            int left = i + 1 - minutes;

            // 同！时！维护忍耐收益数
            tolerenceGain += singleGain[i];
            int outOfWindow = left - 1;
            if (outOfWindow >= 0)
            {
                tolerenceGain -= singleGain[outOfWindow];
            }
            if (tolerenceGain > bestGain)
            {
                bestGain = tolerenceGain;
                bestIndex = left;
            }
        }
        return noChange + bestGain;
    }
};

int q1052()
{
    vector<int>customers{ 1,0,1,2,1,1,7,5 };
    vector<int>grumpy{ 0,1,0,1,0,1,0,1 };
    Solution solution;
    int max = solution.maxSatisfied(customers, grumpy, 3);

    return 0;
}
