class Solution {
public:
    
    vector<vector<int>> res;
    
    void findCombinations(int ind, int k, int sum, int n, vector<int> &ans)
    {
        if(k<0 or sum>n)
            return;
        
        if(k==0 and sum==n)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=ind;i<=9;i++)
        {
            if(sum+i<=n)
            {
                k--;   
                sum+=i;
                
                ans.push_back(i);
                
                findCombinations(i+1,k,sum,n,ans);
                
                ans.pop_back();
                
                k++;
                sum-=i;
            }
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> ans;
        
        findCombinations(1,k,0,n,ans);
        
        return res;
        
    }
};