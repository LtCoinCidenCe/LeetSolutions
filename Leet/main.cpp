#include<iostream>
#include<unordered_map>
int q2644();

int main(int argc, char** argv)
{
	std::unordered_map<std::string, std::string>map;
	auto result1 = map.emplace("3", "cool"); // returns result1.second==true
	auto result2 = map.emplace("3", "stand"); // returns result2.second==false

	q2644();
}
