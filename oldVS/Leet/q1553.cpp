#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution1 {
public:
	int minDays(int n) {
		vector<int>oranges(n + 1, 0);
		oranges[1] = 1;
		for (size_t i = 1; i < n; i++)
		{
			unsigned int nextDay = 3 * i;
			if (nextDay < n + 1)
			{
				oranges[nextDay] = oranges[i] + 1;
			}
			nextDay = 2 * i;
			if (nextDay < n + 1)
			{
				if (oranges[nextDay] == 0)
					oranges[nextDay] = oranges[i] + 1;
				else
					oranges[nextDay] = min(oranges[nextDay], oranges[i] + 1);
			}
			nextDay = i + 1;
			if (nextDay < n + 1)
			{
				if (oranges[nextDay] == 0)
					oranges[nextDay] = oranges[i] + 1;
				else
					oranges[nextDay] = min(oranges[nextDay], oranges[i] + 1);
			}
		}
		return oranges[n];
	}
};

class Solution2 {
public:
	int minDays(int n) {
		if (n < 3)
		{
			return n;
		}
		return 1 + min((n & 1) + minDays(n / 2), n % 3 + minDays(n / 3));
	}
};

class Solution3 {
public:
	struct Station
	{
		int oranges;
		int stationKaksi;
		int stationKolme;
		int nextKaksi;
		int nextKolme;
		int daystillnow = 0;
	};

	int minDays(int n) {
		int result = INT32_MAX;
		unordered_map<int, Station>s;
		queue<int>q;
		s.emplace(n, Station{ n,0,0,0,0,0 });
		q.emplace(n);
		while (!q.empty())
		{
			int current = q.front();
			Station& cs = s[current];
			q.pop();
			if (current<3)
			{
				result = min(cs.daystillnow + current, result);
				continue;
			}
			cs.nextKolme = cs.oranges / 3;
			cs.nextKaksi = cs.oranges / 2;
			auto found = s.find(cs.nextKolme);
			if (found != s.end())
			{
				found->second.stationKolme = current;
				found->second.daystillnow = min(found->second.daystillnow, cs.daystillnow + 1 + current % 3);
			}
			else
			{
				s.emplace(cs.nextKolme, Station{ cs.nextKolme,0,current,0,0,cs.daystillnow + 1 + current % 3 });
				q.emplace(cs.nextKolme);
			}
			found = s.find(cs.nextKaksi);
			if (found != s.end())
			{
				found->second.stationKaksi = current;
				found->second.daystillnow = min(found->second.daystillnow, cs.daystillnow + 1 + (current & 1));
				q.emplace(cs.nextKaksi);
			}
			else
			{
				s.emplace(cs.nextKaksi, Station{ cs.nextKaksi,current,0,0,0,cs.daystillnow + 1 + (current & 1) });
				q.emplace(cs.nextKaksi);
			}
		}
		return result;
	}
};

class Solution4 {
public:
	int minDays(int n) {
		int result = INT32_MAX;
		unordered_map<int, int>s;
		queue<int>q;
		s.emplace(n, 0);
		q.emplace(n);
		while (!q.empty())
		{
			int current = q.front();
			int cdays = s[current];
			q.pop();
			if (current < 3)
			{
				result = min(cdays + current, result);
				continue;
			}
			int nextKolme = current / 3;
			int nextKaksi = current / 2;
			auto found = s.find(nextKolme);
			if (found != s.end())
			{
				// found->second.stationKolme = current;
				found->second = min(found->second, cdays + 1 + current % 3);
			}
			else
			{
				s.emplace(nextKolme, cdays + 1 + current % 3);
				q.emplace(nextKolme);
			}
			found = s.find(nextKaksi);
			if (found != s.end())
			{
				// found->second.stationKaksi = current;
				found->second = min(found->second, cdays + 1 + (current & 1));
				q.emplace(nextKaksi);
			}
			else
			{
				s.emplace(nextKaksi, cdays + 1 + (current & 1));
				q.emplace(nextKaksi);
			}
		}
		return result;
	}
};

int q1553()
{
	Solution4 s;
	int result = s.minDays(45345439);
	return result;
}
