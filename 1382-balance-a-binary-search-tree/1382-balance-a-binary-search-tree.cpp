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
    
    vector<int> inorder;
    
    void findInorder(TreeNode* root)
    {
        if(root!=NULL)
        {
            findInorder(root->left);
            inorder.push_back(root->val);
            findInorder(root->right);    
        }
    }
    
    TreeNode* buildTree(int start, int end)
    {
        if(start>end)
            return NULL;
        
        int mid=(start+end)/2;
        
        TreeNode* root=new TreeNode(inorder[mid]);
        
        root->left=buildTree(start,mid-1);
        root->right=buildTree(mid+1,end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)
            return NULL;
        
        findInorder(root);
        
        int n=inorder.size();
        return buildTree(0,n-1);
    }
};