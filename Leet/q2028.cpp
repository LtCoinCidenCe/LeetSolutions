#include<vector>
using namespace std;


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        int remaining = sum;
        for (int i = 0; i < m; i++)
        {
            remaining -= rolls[i];
        }
        float r = remaining;
        r /= n;
        if (r < 1 || r>6)
            return vector<int>();
        int b = r;
        int ok = b * n;
        int de = remaining - ok;
        vector<int>result(n, b);
        for (int i = 0; i < de; i++)
        {
            result[i]++;
        }
        return result;
    }
};

int q2028()
{
    Solution s;
    vector<int>rolls{ 3,2,4,3 };
    int mean = 4, n = 2;
    s.missingRolls(rolls, mean, n);
    return 0;
}
