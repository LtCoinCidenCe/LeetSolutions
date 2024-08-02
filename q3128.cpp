#include <ranges>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        long long result = 0;

        vector<int> column(m, 0), rows(n, 0);
        for (int i = 0; i < n; i++)
        {
            const vector<int> &theRow = grid[i];
            for (int j = 0; j < m; j++)
            {
                const int point = theRow[j];
                if (point == 1)
                {
                    rows[i] += 1;
                    column[j] += 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            const vector<int> &theRow = grid[i];
            for (int j = 0; j < m; j++)
            {
                const int point = theRow[j];
                if (point == 1)
                {
                    int rowPoints = rows[i];
                    if (rowPoints > 1)
                    {
                        int columnPoints = column[j];
                        if (columnPoints > 1)
                        {
                            int plus = (rowPoints - 1) * (columnPoints - 1);
                            result += plus;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int>> grid{{0, 1, 0}, {0, 1, 1}, {0, 1, 0}};
    long long result = s.numberOfRightTriangles(grid);
    return 0;
}
