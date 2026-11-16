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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if(preorder.size() == 0)return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        auto index = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int left_nodes = distance(inorder.begin(), index);
        int right_nodes = distance(index, inorder.end());
        if(left_nodes)root->left = buildTree(
            // preorder [1, .. , 1+left_nodes]
            vector<int> (preorder.begin() + 1, preorder.begin()+1+left_nodes),
            // inorder [..., index]
            vector<int> (inorder.begin(), index)
        );
        if(right_nodes)root->right = buildTree(
            // preordedr [1+left_nodes, ...]
            vector<int> (preorder.begin() + 1 + left_nodes,
            preorder.end()),
            // inorder [1+index, ...]
            vector<int> (index+1, inorder.end())
        );
        return root;
    }
};
