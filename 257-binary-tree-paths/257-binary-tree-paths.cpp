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
    
    void findPaths(TreeNode* root, string temp, vector<string> &res)
    {
        if(root==NULL)
        {
            return;
        }
       
        if(root->left==NULL and root->right==NULL)
        {
            temp+=to_string(root->val);
            res.push_back(temp);
            return;
        }
        
        temp+=to_string(root->val);
        temp+="->";
        // cout<<temp<<" "<<root->val<<endl;
        
        findPaths(root->left,temp,res);
        findPaths(root->right,temp,res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        string temp="";
        
        findPaths(root,temp,res);
        
        return res;
    }
};