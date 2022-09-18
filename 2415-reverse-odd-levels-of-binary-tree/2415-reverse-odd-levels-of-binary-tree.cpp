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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)
            return NULL;
        
        queue<TreeNode*>q;
        q.push(root);
        int lev = 0;
        vector<int>values;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>temp;
            for(int i =0;i<sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(lev%2)
                    curr->val = values[sz-i-1];

                if(curr->left)
                {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                
                if(curr->right)
                {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            values=temp;
            lev++;
        }
        
        return root;
    }
};