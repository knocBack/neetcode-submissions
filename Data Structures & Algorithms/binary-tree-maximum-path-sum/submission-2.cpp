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
    int maxSum(TreeNode* root, int& ans) {
        if(root == NULL)return 0;
        int leftMax = max(0, maxSum(root->left, ans));
        int rightMax = max(0, maxSum(root->right, ans));
        ans = max(ans, leftMax + rightMax + root->val);
        // cout<<root->val<<' '<<ans<<'\n';
        return max(leftMax, rightMax) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = 0;
        if(root)ans = root->val;
        maxSum(root, ans);
        return ans;
    }
};
