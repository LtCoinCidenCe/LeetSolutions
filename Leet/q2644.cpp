#include<vector>
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        size_t n = nums.size();
        size_t m = divisors.size();
        int highScore = 0;
        int highIndex = 0;
        for (size_t i = 0; i < m; i++)
        {
            int div = divisors[i];
            int score = 0;
            for (size_t j = 0; j < n; j++)
            {
                int number = nums[j];
                if (number % div == 0)
                {
                    score++;
                }
            }
            if (score > highScore)
            {
                highIndex = i;
                highScore = score;
            }
            else if (score==highScore)
            {
                if (div < divisors[highIndex])
                {
                    highIndex = i;
                }
            }
        }
        return divisors[highIndex];
    }
};

int q2644()
{

    return 0;
}
