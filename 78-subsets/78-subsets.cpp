class Solution {
public:
    
    void findSubsets(vector<int> &nums, set<vector<int>> &st,vector<int> &ds, int n,int i)
    {
        if(i==n)
        {
            st.insert(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        findSubsets(nums,st,ds,n,i+1);
        
        ds.pop_back();
        findSubsets(nums,st,ds,n,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();

        set<vector<int>> st;
        vector<vector<int>> res;
        vector<int> ds;
        
        findSubsets(nums,st,ds,n,0);
        
        for(auto it:st)
            res.push_back(it);
        
        return res;
        
    }
};