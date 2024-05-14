#include<vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int totalRefill = 0;
        int n = plants.size();
        int midpoint = plants.size() / 2; // odd then just middle, even then for right
        int remaining = capacityA;
        bool odd = (n & 1) == 1;
        for (int i = 0; i < midpoint; i++)
        {
            int eater = plants[i];
            if (remaining >= eater)
            {
                remaining -= eater;
            }
            else
            {
                totalRefill++;
                remaining = capacityA - eater;
            }
        }
        bool bobEnd = odd && remaining >= plants[midpoint];
        remaining = capacityB;
        for (int i = n - 1; i >= midpoint + bobEnd; i--)
        {
            int eater = plants[i];
            if (remaining >= eater)
            {
                remaining -= eater;
            }
            else
            {
                totalRefill++;
                remaining = capacityB - eater;
            }
        }
        return totalRefill;
    }
};

int q2105()
{
    Solution s;
    vector<int>a{ 2,2,3,3 };
    int result = s.minimumRefill(a, 5, 5);
    return 0;
}
