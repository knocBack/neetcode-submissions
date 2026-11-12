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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* it = NULL;
        TreeNode* ans = NULL;
        queue<TreeNode*> level;
        if(p->val > q->val){
            it = p;
            p = q;
            q = it;
        }
        if(root!=NULL)level.push(root);
        while(!level.empty()){
            it = level.front();
            level.pop();
            if(it->val == p->val || it->val == q->val){
                // both or any one of the value is found
                // implies one is the LCA of other
                ans = it;
                break;
            }
            else if(p->val < it->val && it->val < q->val){
                // this is the node where p and q are separated
                // implies this is the LCA
                ans = it;
                break;
            }
            else if(p->val < it->val){
                // both are towards left, search left
                level.push(it->left);
            }
            else{
                // both are towards right, search right
                level.push(it->right);
            }
        }
        return ans;
    }
};
