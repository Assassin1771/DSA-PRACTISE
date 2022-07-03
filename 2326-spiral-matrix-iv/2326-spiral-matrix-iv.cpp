/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> mat(m, vector<int> (n,-1));
        
        int top=0, bottom=m-1, left=0, right=n-1;
        int direction=1;
        
        ListNode* curr=head;
        while(curr!=NULL and top<=bottom and left<=right)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++)
                {
                    if(curr)
                    {
                        mat[top][i]=curr->val;
                        curr=curr->next;
                    }
                    
                    else
                        return mat;
                }
                
                top++;
                direction=2;
            }
            
            if(direction==2)
            {
                cout<<2<<endl;
                for(int i=top;i<=bottom;i++)
                {   
                    if(curr)
                    {
                        
                        mat[i][right]=curr->val;
                        curr=curr->next;
                    }
                    
                    else
                        return mat;
                }
                
                right--;
                direction=3;
            }
            
            if(direction==3)
            {
                for(int i=right;i>=left;i--)
                {
                    if(curr)
                    {
                        mat[bottom][i]=curr->val;
                        curr=curr->next;
                    }
                    
                    else
                        return mat;
                }
                
                bottom--;
                direction=4;
            }
            
            if(direction==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    if(curr)
                    {
                        mat[i][left]=curr->val;
                        curr=curr->next;
                    }
                    
                    else
                        return mat;
                }
                
                left++;
                direction=1;
            }
        }
        
        return mat;
        
    }
};