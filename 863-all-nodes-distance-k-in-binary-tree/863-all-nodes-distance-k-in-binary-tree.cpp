/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void getparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(!root)
            return;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left)
            {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right)
            {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        
        if(!root)
            return ans;
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*, bool> visited;
        getparent(root,parent);
        
        int lev = 0;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        
        while(!q.empty())
        {
            if(lev == k)
                break;
            int n = q.size();
            
            for(int i =0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            lev++;
        }
        
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            ans.push_back(top->val);
        }
        
        return ans;
    }
};