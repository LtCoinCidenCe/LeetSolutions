#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int high = 0;
        int low = 2000000;
        double all = 0;
        for (int i = 0; i < n; i++)
        {
            int a = salary[i];
            high = max(a, high);
            low = min(a, low);
            all += a;
        }
        return (all - high - low) / (n - 2);
    }
};

double q1491()
{
    Solution s;
    vector<int>salaries{ 1,2,3,4,5 };
    return s.average(salaries);
}
