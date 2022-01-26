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
    
    int res=0;
    TreeNode* res1=NULL;
    
    void preorder(TreeNode* original, TreeNode* target)
    {
        if(original==NULL)
            return;
        
        if(original->val==target->val)
        {
            res=target->val;
            return;
        }
        
        preorder(original->left, target);
        preorder(original->right,target);
    }
    
    void find(TreeNode* cloned, int res)
    {
        if(cloned==NULL)
            return;
        
        if(cloned->val==res)
        {
            res1=cloned;
            return;
        }
        
        find(cloned->left,res);
        find(cloned->right,res);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        preorder(original,target);
        
        find(cloned,res);
            
        return res1;
    }
};