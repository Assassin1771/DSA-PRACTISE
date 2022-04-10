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
    
    int findHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return max(findHeight(root->left),findHeight(root->right))+1;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        int height=findHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        
        int res=0;
        
        while(q.size())
        {
            int count=q.size();
            height--;
            
            for(int i=0;i<count;i++)
            {   
                TreeNode* curr=q.front();
                q.pop();
                 
                if(height==0)
                {
                    res=curr->val;
                    return curr->val;
                }
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
        }
        
        return res;
        
    }
};