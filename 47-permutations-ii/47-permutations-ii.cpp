class Solution {
public:
    
        void findPermutations(int ind, vector<int> &nums, vector<int> &ds, vector<int> &freq, vector<vector<int>> &res)
    {
        if(ind==nums.size())
        {
            res.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i] || i > 0 && nums[i] == nums[i-1] && !freq[i - 1])
                continue;
            
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                
                findPermutations(ind+1,nums,ds,freq,res);
                
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> ds;
        
        sort(nums.begin(),nums.end());
        
        vector<int> freq(nums.size());
        
        findPermutations(0,nums,ds,freq,res);
        
        return res;
        
    }
};