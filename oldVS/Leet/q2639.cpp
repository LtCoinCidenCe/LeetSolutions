#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<int>result;
        for (int i = 0; i < n; i++)
        {
            int width = 0;
            for (int j = 0; j < m; j++)
            {
                string str = to_string(grid[j][i]);
                if (str.size() > width)
                {
                    width = str.size();
                }
            }
            result.push_back(width);
        }
        return result;
    }
};

int q2639()
{
    vector<vector<int>>grid{ {-15,1,3},{15,7,12},{5,6,-2} };
    Solution s;
    vector<int>wide = s.findColumnWidth(grid);
    return 0;
}
