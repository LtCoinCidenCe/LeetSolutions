class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int main = mainTank, ad = additionalTank;
        // just think anti-clockwise
        int total;
        if (main >= 1 + 4 * ad)
        {
            total = main + ad;
        }
        else
        {
            int times = (main - 1) / 4;
            total = main + times;
        }
        return total * 10;
    }
};

int q2739()
{
    Solution s;
    int car = s.distanceTraveled(100, 26);
    return 0;
}
