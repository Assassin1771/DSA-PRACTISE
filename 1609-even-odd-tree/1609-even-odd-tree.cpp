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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level=-1;
        int prev=0;
        while(q.size())
        {
            int count=q.size();
            level++;
            
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                // cout<<curr->val<<' '<<count<<endl;
                
                if(level%2==0)
                {
                    if(curr->val%2==0)
                    {
                        // cout<<curr->val<<endl;
                        // cout<<1<<endl;
                        return false;
                    }
                    
                    if(i>0 and prev>=curr->val)
                    {
                        // cout<<curr->val<<endl;
                        // cout<<2<<endl;
                        return false;
                    }
                }
                
                else
                {
                    if(curr->val%2==1)
                    {
                        // cout<<curr->val<<endl;
                        // cout<<3<<endl;
                        return false;
                    }
                    
                    if(i>0 and prev<=curr->val)
                    {
                        // cout<<curr->val<<endl;
                        // cout<<4<<endl;
                        return false;
                    }
                }
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
                prev=curr->val;
            }
            
            // level++;
            prev=0;
        }
        
        return true;
        
    }
};