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
        
        queue<pair<TreeNode*, long long int>>q;
        q.push({root, 0});
        
        long long int ans = 0;
        
        while(!q.empty())
        {
            long long int size = q.size();
            long long int minval = q.front().second;
            long long int first=0, last = 0;
            
            for(int i =0 ; i < size;i++)
            {
                long long int val = q.front().second - minval;
                TreeNode* node = q.front().first;
                
                q.pop();
                
                if(i == 0)
                    first = val;
                if( i == size -1)
                    last = val;
                
                if(node->left)
                    q.push({node->left, 2*val+1});
                
                if(node->right)
                    q.push({node->right, 2*val+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};