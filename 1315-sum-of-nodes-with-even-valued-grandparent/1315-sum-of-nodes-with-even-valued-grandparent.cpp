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
    int sumEvenGrandparent(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int res=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                    
                    if(temp->val%2==0)
                    {
                        if(temp->left->left)
                        res+=temp->left->left->val;
                    
                        if(temp->left->right)
                        res+=temp->left->right->val;    
                    }
                    
                }
                    
                if(temp->right)
                {
                    q.push(temp->right);
                    
                    if(temp->val%2==0)
                    {
                        if(temp->right->right)
                        res+=temp->right->right->val;
                
                        if(temp->right->left)
                        res+=temp->right->left->val;  
                    }
                    
                }
            }
        }
        
        return res;
        
    }
};