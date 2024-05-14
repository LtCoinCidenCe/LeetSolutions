#include<vector>
#include<algorithm>
using namespace std;
class SolutionOld {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, -1)));

        dp[0][0][0] = grid[0][0];
        for (int k = 1; k <= 2 * n - 2; k++)
        {
            // 总共走k步
            for (int i = 0; i < n; i++)
            {
                if (i > k)
                {
                    break;
                }
                if (k - i >= n)
                {
                    continue;
                }
                // a子下i步,现位置(i,k-i)
                int dessertA = grid[i][k - i];
                if (dessertA == -1)
                {
                    continue;
                }
                for (int j = 0; j < n; j++)
                {
                    if (j > k)
                    {
                        break;
                    }
                    if (k - j >= n)
                    {
                        continue;
                    }
                    // b子下j步，现位置(j,k-j)
                    int dessertB = grid[j][k - j];
                    if (dessertB == -1)
                    {
                        continue;
                    }
                    if (i == j)
                    {
                        dessertB = 0;
                    }
                    int update;
                    if (i != 0 && j != 0)
                    {
                        int iStayRow = max(dp[k - 1][i][j], dp[k - 1][i][j - 1]);
                        int otherPart = max(dp[k - 1][i - 1][j], dp[k - 1][i - 1][j - 1]);
                        update = max(iStayRow, otherPart);
                    }
                    else if (i == 0 && j != 0)
                    {
                        update = max(dp[k - 1][i][j], dp[k - 1][i][j - 1]);
                    }
                    else if (i != 0 && j == 0)
                    {
                        update = max(dp[k - 1][i][j], dp[k - 1][i - 1][j]);
                    }
                    else if (i == 0 && j == 0)
                    {
                        update = dp[k - 1][i][j];
                    }
                    if (update != -1)
                    {
                        update += dessertA + dessertB;
                    }
                    dp[k][i][j] = update;
                }
            }
        }
        if (dp[2 * n - 2][n - 1][n - 1] == -1)
        {
            return 0;
        }
        return dp[2 * n - 2][n - 1][n - 1];
    }
};

int q741()
{
    SolutionOld s;
    vector<vector<int>>test{ {1,1,-1},{1,-1,1},{-1,1,1} };
    int result = s.cherryPickup(test);
    return 0;
}
