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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int lvl = 0;
        queue<TreeNode*> level;
        queue<TreeNode*> q;
        TreeNode* it = NULL;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            while(!q.empty()){
                it = q.front();
                if(it->left)level.push(it->left);
                if(it->right)level.push(it->right);
                if(ans.size()==lvl)ans.push_back({});
                ans[lvl].push_back(it->val);
                q.pop();
            }
            lvl++;
            while(!level.empty()){
                q.push(level.front());
                level.pop();
            }
        }
        return ans;
    }
};
