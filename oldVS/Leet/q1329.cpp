#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int high = max(m, n);
        int low = min(m, n);
        int sum = m + n;

        vector<vector<int>>result(m, vector<int>(n, 0));
        for (int i = 0; i < sum - 1; i++)
        {
            int x = 0;
            int y = m - 1 - i;
            if (y<0)
            {
                x -= y;
                y = 0;
            }
            // start = [y][x];
            // read diagonal vector
            vector<int>diagonal;
            for (size_t j = 0; j < low; j++)
            {
                if (y + j >= m)
                {
                    break;
                }
                if (x + j >= n)
                {
                    break;
                }
                diagonal.push_back(mat[y + j][x + j]);
            }
            sort(diagonal.begin(), diagonal.end());
            for (size_t j = 0; j < low; j++)
            {
                if (y + j >= m)
                {
                    break;
                }
                if (x + j >= n)
                {
                    break;
                }
                result[y + j][x + j] = diagonal[j];
            }
        }
        return result;
    }
};


int q1329()
{
    Solution s;
    vector<vector<int>>mm = {
        vector<int>{3,3,1,1},
        vector<int>{2,2,1,2},
        vector<int>{1,1,1,2}
    };
    s.diagonalSort(mm);
    return 0;
}
