#include<vector>
#include<set>
#include<queue>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>values;
        priority_queue<int>valueSort;
        values.emplace_back(vector<int>{matrix[0][0]});
        valueSort.emplace(matrix[0][0]);
        for (int i = 1; i < n; i++)
        {
            int vv = values[0][i - 1] ^ matrix[0][i];
            values[0].emplace_back(vv);
            valueSort.emplace(vv);
        }
        for (int j = 1; j < m; j++)
        {
            values.emplace_back(vector<int>());
            int vv = values[j - 1][0] ^ matrix[j][0];
            values[j].emplace_back(vv);
            valueSort.emplace(vv);
            for (int i = 1; i < n; i++)
            {
                vv = values[j - 1][i] ^ values[j][i - 1] ^ values[j - 1][i - 1] ^ matrix[j][i];
                values[j].emplace_back(vv);
                valueSort.emplace(vv);
            }
        }
        int result = 0;

        /*set<int>::reverse_iterator r_iterator = valueSort.rbegin();
        set<int>::reverse_iterator rend = valueSort.rend();
        for (int i = 0; i < k; i++)
        {
            if (r_iterator==rend)
            {
                result = 0;
                break;
            }
            result = *r_iterator;
            r_iterator++;
        }*/
        for (int i = 0; i < k; i++)
        {
            result = valueSort.top();
            valueSort.pop();
        }
        return result;
    }
};

int q1738()
{
    Solution s;
    int result = 0, k = 10, k2 = 3;
    vector<vector<int>>matrix2{ {5,2},{1,6} };
    vector<vector<int>>matrix{ {10,9,5},{2,0,4},{1,0,9},{3,4,8} };
    result = s.kthLargestValue(matrix, k);
    return result;
}
