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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int len = 0;
        stack<TreeNode*> st;
        while(cur || !st.empty()){
            // in-order left, mid, right

            // go further to the left, push into stack as you go
            while(cur){
                st.push(cur);
                cur = cur->left;
            }

            // no more left, pop the top of the stack and process
            cur = st.top();
            st.pop();
            len++; // processing elements in this order
            // cout<<cur->val<<' '<<len<<'\n';
            if(len == k)return cur->val;

            // process right elements now.
            // if(cur->right)st.push(cur->right);
            cur = cur->right;
        }
    }
};
