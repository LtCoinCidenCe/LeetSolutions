#include<vector>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        // one way cost i+1
        int totalCost = 0;
        int n = plants.size();
        int remaining = 0;
        for (int i = 0; i < n; i++)
        {
            int eater = plants[i];
            if (remaining - eater < 0)
            {
                int times = eater / capacity;
                remaining = eater % capacity;
                // fill
            }
        }
    }
};


int q2079()
{
	return 0;
}
