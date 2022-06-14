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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    vector<vector<int>> res;
    
    if(root==NULL)
        return res;
        
    queue<TreeNode*> q; 
    stack <int> st;
    
    q.push(root);
    
    bool reverse=false;
    
    vector<int> temp;
    
    while(q.size())
    {
        int curr_size=q.size();
        for(int i=0;i<curr_size;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr)
            {
                if(reverse)
                    st.push(curr->val);
            
                else
                    temp.push_back(curr->val);
            }
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        
        while(st.size())
        {
            int value=st.top();
            st.pop();
            
            temp.push_back(value);
        }
        
        res.push_back(temp);
        temp.clear();
        
        reverse=!reverse;
    }
    
    return res;
        
    }
};