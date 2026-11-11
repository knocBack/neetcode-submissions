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
    // checks if both trees are same or not
    bool isSametree(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL && r2 == NULL)return true;
        if(r1 == NULL || r2==NULL)return false;
        if(r1->val == r2->val)return isSametree(r1->left, r2->left) && isSametree(r1->right, r2->right);
        return false;
    }
public:
    // compares two root nodes with same values, if one is sub-root of other, it returns true
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL)return true;
        if(root == NULL || subRoot==NULL)return false;
        if(root->val == subRoot->val){
            if(isSametree(root, subRoot))return true; // check if the subRoot is true
        }
        // else check the same with child nodes.
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
