#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        size_t n = profit.size();
        size_t m = worker.size();
        vector<int>profitRank(n, 0);
        iota(profitRank.begin(), profitRank.end(), 0);
        sort(profitRank.begin(), profitRank.end(), [&](int a, int b) {return profit[a] > profit[b]; });

        sort(worker.begin(), worker.end(), greater<int>());

        int p = 0;
        int result = 0;
        for (size_t i = 0; i < m; i++)
        {
            int abil = worker[i];
            int dfct = difficulty[profitRank[p]];

            while (abil < dfct)
            {
                p++;
                if (p >= n)
                {
                    return result;
                }
                dfct = difficulty[profitRank[p]];
            }

            result += profit[profitRank[p]];
        }
        return result;
    }
};

int q826()
{
    vector<int>a{ 2, 4, 6, 8, 10 };
    vector<int>b{ 10,20,30,40,50 };
    vector<int>c{ 4,5,6,7 };
    Solution s;
    int result;
    result = s.maxProfitAssignment(a, b, c);
    return 0;
}
