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
    
    void traversal(TreeNode* root, int level, int &prev, int &ans)
    {
        if(!root)
            return;
        
        if(!root->left && !root->right)
        {
            if(level > prev)
            {
                ans = root->val;
                prev = level;
            }
            return;
        }
        
        traversal(root->left, level+1, prev, ans);
        traversal(root->right, level+1, prev, ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int prev = 0, ans = 0;
        traversal(root, 1, prev, ans);
        
        return ans;
    }
};