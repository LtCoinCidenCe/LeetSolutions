// Definition for a binary tree node.
#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right)
  {
  }
};

class Solution {
public:
  int subRootVal;
  vector<TreeNode *> targets;
  void findSubRoot(TreeNode *current)
  {
    if (current->val == subRootVal) {
      targets.push_back(current);
    }
    if (current->left) {
      findSubRoot(current->left);
    }
    if (current->right) {
      findSubRoot(current->right);
    }
  }
  bool compareTrees(TreeNode *oneTree, TreeNode *twoTree)
  {
    if (oneTree->val != twoTree->val) {
      return false;
    }
    // two leaf node ok
    // single or both available compare ok
    // others bad
    if (oneTree->left) {
      if (twoTree->left) {
        bool leftSame = compareTrees(oneTree->left, twoTree->left);
        if (!leftSame) {
          return false;
        }
        // left compare same ok for now
      }
      else // twoTree left missing
      {
        return false;
      }
    }
    else // oneTree left missing
    {
      if (twoTree->left) {
        return false;
      }
      else // twoTree left missing
      {
        // ok for now
      }
    }

    // left tree is ok

    if (oneTree->right) {
      if (twoTree->right) {
        return compareTrees(oneTree->right, twoTree->right);
      }
      else // twoTree right missing
      {
        return false;
      }
    }
    else // oneTree right missing
    {
      if (twoTree->right) {
        return false;
      }
      else // twoTree right missing
      {
        return true;
      }
    }
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    subRootVal = subRoot->val;
    findSubRoot(root);

    return ranges::any_of(targets, [&](TreeNode *inRoot) {
      return compareTrees(inRoot, subRoot);
    });
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  TreeNode oneTree[6]{TreeNode(0), TreeNode(1), TreeNode(2),
                      TreeNode(3), TreeNode(4), TreeNode(5)};
  oneTree[3].left = oneTree + 4;
  oneTree[3].right = oneTree + 5;
  oneTree[4].left = oneTree + 1;
  oneTree[4].right = oneTree + 2;

  TreeNode twoTree[6]{TreeNode(0), TreeNode(1), TreeNode(2),
                      TreeNode(3), TreeNode(4), TreeNode(5)};
  twoTree[4].left = twoTree + 1;
  twoTree[4].right = twoTree + 2;
  bool result = sln.isSubtree(oneTree + 3, twoTree + 4);
  return 0;
}
