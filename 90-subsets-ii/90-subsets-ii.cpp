class Solution {
public:
        
    void findSubsets(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res)
    {
        res.push_back(temp);
        
        for(int i=ind;i<nums.size();i++)
        {        
            if(i>ind and nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            findSubsets(i+1,nums,temp,res);
            
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        
        int ind=0;
        
        findSubsets(ind,nums,temp,res);
        
        return res;
       
        
    }
};