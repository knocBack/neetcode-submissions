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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* it = NULL;
        string s = "";
        if(root)q.push(root);
        while(!q.empty()){
            it = q.front();
            q.pop();
            if(it){
                s+=to_string(it->val);
                q.push(it->left);
                q.push(it->right);
            }
            s+=',';
        }
        // cout<<s<<'\n';
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        int val;
        queue<TreeNode*> q;
        queue<TreeNode*> processor;
        TreeNode *root = NULL, *it = NULL;
        TreeNode *left = NULL, *right = NULL;
        while(getline(ss, token, ',')){
            // cout<<token<<',';
            if(token!=""){
                val = stoi(token);
                q.push(new TreeNode(val));
            }
            else q.push(nullptr);
        }
        if(!q.empty()){
            root = q.front();
            q.pop();
            it = root;
            processor.push(root);
        }
        while(!processor.empty()){
            left = NULL;right = NULL;
            if(!q.empty()){left = q.front();q.pop();}
            if(!q.empty()){right = q.front();q.pop();}
            it = processor.front();
            processor.pop();
            it->left = left;
            it->right = right;
            if(left)processor.push(left);
            if(right)processor.push(right);
        }
        return root;
    }
};
