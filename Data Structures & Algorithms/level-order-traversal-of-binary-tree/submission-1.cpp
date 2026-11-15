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
        int qsize = 0;
        queue<TreeNode*> q;
        TreeNode* it = NULL;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            qsize = q.size();
            vector<int> level; // creating a new level everytime because it can be pushed into ans with reference
            for(int i=0;i<qsize;i++){
                it = q.front();
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
                level.push_back(it->val);
            }
            ans.push_back(move(level));
        }
        return ans;
    }
};
