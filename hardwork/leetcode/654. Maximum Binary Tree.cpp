#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
          return NULL;
        } else {
          auto root_value_it = max_element(nums.begin(), nums.end());
          auto root_node = new TreeNode{ *root_value_it };
          // cout << root_node->val << '-';
          auto left = vector<int> {nums.begin(), root_value_it};
          auto right = vector<int> {root_value_it + 1, nums.end()};
          root_node->left = constructMaximumBinaryTree(left);
          root_node->right = constructMaximumBinaryTree(right);
          return root_node;
        }
    }
};

int main() {
  auto v = vector<int> { 3,2,1,6,0,5};
  auto s = Solution();
  s.constructMaximumBinaryTree(v);
}