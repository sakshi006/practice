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
    vector<int>v;
    
    void dfs(TreeNode* root, int &sum)
    {
        if(!root)
            return;
        
        if(root->left && root->left->left && root->val % 2 == 0)
            sum += root->left->left->val;
        
        if(root->left && root->left->right && root->val % 2 == 0)
            sum += root->left->right->val;
        
        if(root->right && root->right->left && root->val % 2 == 0)
            sum += root->right->left->val;
        
        if(root->right && root->right->right && root->val % 2 == 0)
            sum += root->right->right->val;
        
        dfs(root->left,sum);
        dfs(root->right,sum);
            
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int sum = 0;
        dfs(root, sum);
        
        return sum;
        
    }
};