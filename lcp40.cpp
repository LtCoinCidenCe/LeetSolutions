#include <ranges>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        int n = cards.size();
        ranges::sort(cards, greater());
        int score = 0;
        bool activeHasOdd = false, activeHasEven = false,
             reserveHasOdd = false, reserveHasEven = false;
        for (int i = 0; i < cnt; i++)
        {
            int card = cards[i];
            if ((card & 1) == 0)
            {
                activeHasEven = true;
            }
            else
            {
                activeHasOdd = true;
            }
            score += cards[i];
        }

        if ((score & 1) == 0)
        {
            return score;
        }

        int lastActive = cards[cnt - 1];
        bool lastActiveIsOdd = lastActive & 1;

        int lastActiveR = INT32_MAX;
        for (int i = cnt - 2; i >= 0; i--)
        {
            if ((cards[i] & 1) == !lastActiveIsOdd)
            {
                lastActiveR = cards[i];
                break;
            }
        }

        // find exchangable reservist for last active
        int indexForLast = n, indexForR = n;

        auto reservist = find_if(cards.begin() + cnt, cards.end(), [&](int a)
                                 { return (a & 1) == !lastActiveIsOdd; });

        auto rR = find_if(cards.begin() + cnt, cards.end(), [&](int a)
                          { return (a & 1) == lastActiveIsOdd; });

        int reservistLoss = INT32_MAX;
        if (reservist != cards.end())
        {
            reservistLoss = lastActive - *reservist;
        }

        if (lastActiveR != INT32_MAX && rR != cards.end())
        {
            reservistLoss = min(reservistLoss, lastActiveR - *rR);
        }

        if (reservistLoss != INT32_MAX)
        {
            return score - reservistLoss;
        }

        return 0;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> cards{2, 1, 9, 8};
    int cnt = 3;
    int result = s.maxmiumScore(cards, cnt);
    return 0;
}
