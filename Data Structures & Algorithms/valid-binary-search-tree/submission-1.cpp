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
public:
    bool isValidBST(TreeNode* root) {
        pair<TreeNode*, pair<int,int>> it;
        int cur_val, mini, maxi;
        queue<pair<TreeNode*, pair<int,int>>> q;
        if(root)q.push({root, {INT_MIN, INT_MAX}});
        while(!q.empty()){
            it = q.front();
            cur_val = it.first->val;
            mini = it.second.first;
            maxi = it.second.second;
            q.pop();
            if(mini > cur_val || cur_val > maxi)return false;
            if(it.first->left)q.push({it.first->left, {mini, cur_val-1}});
            if(it.first->right)q.push({it.first->right, { cur_val+1, maxi}});
        }
        return true;
    }
};
