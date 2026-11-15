/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool check(TreeNode* cur, int low, int high){
        if(cur == NULL)return true;
        if(low > cur->val || high < cur->val)return false;
        return check(cur->left, low, cur->val-1) && check(cur->right, cur->val+1, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};
