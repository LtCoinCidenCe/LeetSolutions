#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // map of (node, its neighbors)
        unordered_map<int, vector<int>>links;
        links.reserve(600);
        // q (tree, parent)
        queue<pair<TreeNode*, int>>q;
        // q.emplace(root);
        // root doesn't do parent
        int current = root->val;
        auto presentation = links.emplace(current, vector<int>());
        presentation.first->second.reserve(3);
        if (root->left)
        {
            presentation.first->second.push_back(root->left->val);
            q.emplace(root->left, root->val);
        }
        if (root->right)
        {
            presentation.first->second.push_back(root->right->val);
            q.emplace(root->right, root->val);
        }
        while (!q.empty())
        {
            pair<TreeNode*, int>tn = q.front();
            q.pop();
            int parent = tn.second;
            current = tn.first->val;
            presentation = links.emplace(current, vector<int>());
            presentation.first->second.reserve(3);
            presentation.first->second.push_back(parent);
            if (tn.first->left)
            {
                presentation.first->second.push_back(tn.first->left->val);
                q.emplace(tn.first->left, current);
            }
            if (tn.first->right)
            {
                presentation.first->second.push_back(tn.first->right->val);;
                q.emplace(tn.first->right, current);
            }
        }

        int maxDistance = 0;
        // (node, parent)
        queue<pair<int,int>>calculating;
        calculating.emplace(start, start);
        int candidates = 1;
        int nextLevel = 0;
        while (!calculating.empty())
        {
            pair<int,int> current = calculating.front();
            calculating.pop();
            const vector<int>& itsVector = links[current.first];
            int newItems = 0;
            for (size_t i = 0; i < itsVector.size(); i++)
            {
                if (itsVector[i] != current.second)
                {
                    calculating.emplace(itsVector[i], current.first);
                    newItems++;
                }
            }
            
            nextLevel += newItems;
            --candidates;
            if (candidates == 0)
            {
                maxDistance++;
                candidates = nextLevel;
                nextLevel = 0;
            }
        }
        return maxDistance - 1;
    }
};

int q2385()
{
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(5, nullptr, new TreeNode(4, new TreeNode(9), new TreeNode(2))), new TreeNode(3, new TreeNode(10), new TreeNode(6)));
    int result = s.amountOfTime(root, 3);
    return 0;
}
