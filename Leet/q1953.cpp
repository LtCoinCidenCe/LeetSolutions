#include<vector>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        size_t n = milestones.size();
        int biggest = 0;
        long long sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            biggest = max(biggest, milestones[i]);
            sum += milestones[i];
        }
        long long rest = sum - biggest;
        if (biggest <= rest + 1)
        {
            return sum;
        }
        else
        {
            return rest + rest + 1;
        }
    }
};

int q1953()
{
    Solution s;
    int result = 0;
    vector<int>a{ 1,2,3 };
    result = s.numberOfWeeks(a);
    return result;
}
