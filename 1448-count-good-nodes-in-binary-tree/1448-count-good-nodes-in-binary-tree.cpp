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
    
    void preorder(TreeNode* root, int max, int &ct)
    {
        if(!root)
            return;
        if(max<=root->val)
        {
            max=root->val;
            ct++;
        }
        
        // cout<<max<<" "<<ct<<" "<<root->val<<endl;
        preorder(root->left, max, ct);
        preorder(root->right, max, ct);
    }
    
    int goodNodes(TreeNode* root) {
        int ct = 0;
        
        preorder(root->left,root->val,ct); // 2
        preorder(root->right,root->val,ct);
        
        return ct+1;
    }
};