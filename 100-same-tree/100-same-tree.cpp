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
    
    bool check(TreeNode *p, TreeNode *q)
    {
        
        if(p==NULL and q!=NULL)
            return false;
        
        if(q==NULL and p!=NULL)
            return false;
        
        if(p==NULL and q==NULL)
            return true;
        
        return ((p->val==q->val) and (check(p->left,q->left)) and (check(p->right,q->right)));
    }
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return check(p,q);
            
        
    }
};