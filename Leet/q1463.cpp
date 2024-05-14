#include<vector>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int t = 1; t < m; t++)
        {
            for (int i = 0; i < n; i++)
            {
                int lasti[3] = { i - 1,i,i + 1 };
                for (int j = 0; j < n; j++)
                {
                    int current = dp[t][i][j];
                    int lastj[3] = { j - 1,j,j + 1 };
                    for (int a = 0; a < 3; a++)
                    {
                        int robotLast = lasti[a];
                        if (robotLast<0 || robotLast>n - 1)
                        {
                            continue;
                        }
                        for (int b = 0; b < 3; b++)
                        {
                            int roboottiLast = lastj[b];
                            if (roboottiLast<0 || roboottiLast>n - 1)
                            {
                                // 出界
                                continue;
                            }
                            int update = dp[t - 1][robotLast][roboottiLast];
                            current = max(update, current);
                        }
                    }
                    if (current > -1)
                    {
                        if (i == j)
                        {
                            // 采集同一块
                            dp[t][i][j] = current + grid[t][i];
                        }
                        else
                        {
                            dp[t][i][j] = current + grid[t][i] + grid[t][j];
                        }
                    }
                }
            }
        }
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                best = max(best, dp[m - 1][i][j]);
            }
        }
        return best;
    }
};

int q1463()
{
    Solution s;
    vector<vector<int>>grid{ {3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1} };

    return s.cherryPickup(grid);
}
