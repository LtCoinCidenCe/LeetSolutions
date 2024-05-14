#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        auto aa=count_if(hours.begin(), hours.end(), [target](int a) {return a >= target; });
        return aa;
    }
};

int q2798()
{
    vector<int>ddddd{ 5,1,9,2,7 };
    int target = 5;
    Solution s;
    int number=s.numberOfEmployeesWhoMetTarget(ddddd, target);
    return 0;
}