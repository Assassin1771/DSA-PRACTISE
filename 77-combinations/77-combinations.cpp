class Solution {
public:
    
    vector<vector<int>> res;
    
    void findCombinations(int ind, int n, int k, vector<int> &ans)
    {
        if(ans.size()==k)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=ind;i<=n;i++)
        {
            ans.push_back(i);
            
            findCombinations(i+1,n,k,ans);
            
            ans.pop_back();
        }
            
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> ans;
        findCombinations(1,n,k,ans);
        
        return res;
        
    }
};