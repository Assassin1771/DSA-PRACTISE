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
    
    int calculateHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return max(calculateHeight(root->left),calculateHeight(root->right))+1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int height=calculateHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        vector<int> temp;
        
        if(!root)
            return res;
        
        while(q.size())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr)
                temp.push_back(curr->val);
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
                
    }
};