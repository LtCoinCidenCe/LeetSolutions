#include<vector>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tested = 0;
        int n = batteryPercentages.size();
        for (int i = 0; i < n; i++)
        {
            if (batteryPercentages[i] - tested > 0)
            {
                tested++;
            }
        }
        return tested;
    }
};