#include<queue>
#include<string>
#include<iostream>

struct IDDATA
{
	int a;
	std::string b;

	// There is no accesibility issue (no private), so it doesn't need friend.
	// friend bool operator<(const IDDATA& first, const IDDATA& second);
};

inline bool operator<(const IDDATA& first, const IDDATA& second)
{
	return first.a < second.a;
}

struct CustomLess
{
	bool operator()(const IDDATA& l, const IDDATA& r) const { return l < r; }
};

int dataStructures()
{
#pragma region priority_queue
	std::less whatisless;
	whatisless.operator()(4, 2);
	std::priority_queue<IDDATA, std::vector<IDDATA>, CustomLess>theQ;
	theQ.emplace(0, "Hello");
	theQ.emplace(3, "Ink");
	theQ.emplace(9, "Noob");
	theQ.emplace(4, "Demon");
	theQ.emplace(1, "Slayer");
	theQ.emplace(2, "God");
	theQ.size();

	for (; !theQ.empty(); theQ.pop())
	{
		IDDATA element = theQ.top();
		std::cout << '{' << element.a << ",\"" << element.b << "\"}" << std::endl;
	}
#pragma endregion



	return 0;
}
