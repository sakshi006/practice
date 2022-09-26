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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        long long  ans =0;

        
        while(!q.empty())
        {
            long long n=q.size();
            long long minval = q.front().second;
            long long first = 0,last = 0;            
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front().first;
                long long val = q.front().second-minval;
                q.pop();
                
                if(i==0)
                    first = val;
                if(i==n-1)
                    last = val;
                
                if(node->left)
                    q.push({node->left, 2*val+1});
                if(node->right)
                    q.push({node->right, 2*val+2});
            }
            
            ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};