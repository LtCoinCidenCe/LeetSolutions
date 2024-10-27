#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>result(n, 0);
        if (k == 0)
            return result;
        if (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                // result[i]
                int temp = 0;
                for (int j = 0; j < k; j++)
                {
                    int index = (i + j + 1) % n;
                    temp += code[index];
                }
                result[i] = temp;
            }
            return result;
        }
        if (k < 0)
        {
            for (int i = 0; i < n; i++)
            {
                int temp = 0;
                for (int j = 0; j > k; j--)
                {
                    int index = (i + j - 1) % n;
                    index = index < 0 ? index + n : index;
                    temp += code[index];
                }
                result[i] = temp;
            }
            return result;
        }
        return result;
    }
};

int q1652()
{
    vector<int>code{ 2,4,9,3 };
    int k = -2;
    Solution s;
    vector<int>result = s.decrypt(code, k);
    return 0;
}
