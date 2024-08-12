#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class MagicDictionaryWeak {
public:
  unordered_map<int, unordered_set<string>> dict;
  MagicDictionaryWeak() {}

  void buildDict(vector<string> dictionary)
  {
    for (auto &&str : dictionary) {
      dict[str.size()].insert(str);
    }
  }

  bool search(string searchWord)
  {
    int n = searchWord.size();
    if (dict[n].size() == 0) {
      return false;
    }

    for (int i = 0; i < n; i++) {
      string modified = searchWord;
      char &c = modified[i];
      for (int b = 0; b < 26; b++) {
        c = 'a' + b;
        if (c == searchWord[i]) {
          continue;
        }
        if (dict[n].contains(modified)) {
          return true;
        }
      }
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(int argc, char **argv)
{
  MagicDictionaryWeak sln;
  vector<string> dict{"hello", "leetcode"};
  sln.buildDict(dict);
  bool result = sln.search("hlllo");

  return 0;
}
