#include<vector>
using namespace std;

int katu = 0;
class Station
{
public:
	Station(int Stage)
	{
		stage = Stage;
		available = false;
		lastStages = new int[katu];
		forest = 0;
	}
	~Station()
	{
		delete[]lastStages;
	}

	//题目只关心forest，只做了vector<forest>
	int stage;
	bool available;
	int* lastStages;
	int forest;
};

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int roads = nums.size();

		katu = roads;

		vector<Station*>stations(target + 1);
		for (int i = 0; i <= target; i++)
		{
			Station* currentStation = new Station(i);
			stations.push_back(currentStation);
			for (int j = 0; j < roads; j++)
			{
				int deduct = nums[j];
				int possibleLastStage = i - deduct;
				if (possibleLastStage < 0 || stations.size() - 1 < possibleLastStage)
				{
					continue;
				}
				if (possibleLastStage == 0)
				{
					currentStation->available = true;
					currentStation->lastStages[j] = possibleLastStage;
					currentStation->forest += 1;
					if (currentStation->forest > INT_MAX)
					{
						currentStation->available = false;
					}
					continue;
				}
				Station* theLastStation = stations[possibleLastStage];
				if (theLastStation->available)
				{
					currentStation->available = true;
					currentStation->lastStages[j] = possibleLastStage;
					currentStation->forest += theLastStation->forest;
					if (currentStation->forest > INT_MAX)
					{
						currentStation->available = false;
					}
				}
			}
		}
		return stations[target]->forest;
	}
};

int q377()
{
	vector<int>nums{ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111 };
	int target = 999;
	Solution solution;
	int result = solution.combinationSum4(nums, target);
	return 0;
}
