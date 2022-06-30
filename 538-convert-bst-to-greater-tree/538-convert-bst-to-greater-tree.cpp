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
    
    bool isLeaf(TreeNode* root)
    {
        if(root->left==NULL and root->right==NULL)
            return true;
        
        return false;
    }
    
    void maxTree(TreeNode* root, int &sum)
    {   
        if(root==NULL)
            return;
        // cout<<root->val<<" "<<sum<<" "<<"first"<<endl;
        
        if(isLeaf(root))
        {
            root->val+=sum;
            sum=root->val;
            
            // cout<<root->val<<" "<<sum<<" "<<"first"<<endl;
            
            return;
        }
        
        maxTree(root->right,sum);
        
        root->val+=sum;
        sum=root->val;
        
        maxTree(root->left,sum);
        
        // cout<<root->val<<" "<<sum<<" "<<"second"<<endl;

    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(!root)
            return NULL;
        
        int sum=0;
        maxTree(root,sum);
        
        return root;
    }
};