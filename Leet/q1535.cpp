#include<vector>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int defender = 0;
        int challenger = 1;
        int winStreak = 0;
        while (winStreak < k)
        {
            int def = arr[defender];
            int cha = arr[challenger];
            if (def>cha)
            {
                winStreak++;
                challenger++;
            }
            else if (def<cha)
            {
                winStreak = 1;

                defender = challenger;
                challenger++;
            }
            if (challenger == defender)
            {
                challenger++;
            }
            if (challenger == n)
            {
                challenger = 0;
            }
            if (challenger == defender)
            {
                challenger++;
            }
        }
        return arr[defender];
    }
};

class Solution2 {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int defender = 0;
        int challenger = 1;
        int winStreak = 0;
        while (winStreak < k)
        {
            int def = arr[defender];
            int cha = arr[challenger];
            if (def > cha)
            {
                winStreak++;
                challenger++;
            }
            else // if (def < cha)
            {
                winStreak = 1;

                defender = challenger;
                challenger++;
            }
            if (challenger == n)
            {
                break;
            }
        }
        return arr[defender];
    }
};

int q1535()
{
    vector<int>gamers{ 2,1,3,5,4,6,7 };
    Solution2 s;
    int result = s.getWinner(gamers, 2);
    return 0;
}
