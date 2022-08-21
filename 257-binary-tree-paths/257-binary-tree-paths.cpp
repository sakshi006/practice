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
    
    void inorder(TreeNode* root, vector<string>&ans, string s)
    {
        
        if(!root)
            return;
        
        if(!root->left && !root->right)
        {
            s+= to_string(root->val);
            ans.push_back(s);
            return;
        }
        
        s+= to_string(root->val);
        inorder(root->left, ans, s+"->");
        inorder(root->right, ans, s+"->");
     }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root)
            return ans;
        
        string s="";
        inorder(root,ans, s);
        
        return ans;
    }
};