class Solution {
public:
    
    int findCombinations(int ind, int sum, vector<int> &nums, int target, vector<int> &dp)
    {           
        if(sum==target)
            return 1;
        
        if(dp[sum]!=-1)
            return dp[sum];
        
        dp[sum]=0;
        
        for(int i=0;i<nums.size();i++)
        {   
            if(sum+nums[i]<=target)
            {    
                sum+=nums[i];
                
                dp[sum-nums[i]]+=findCombinations(i,sum,nums,target,dp);
                
                sum-=nums[i];
            }
        }
        
        return dp[sum];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1,-1);
        
        return findCombinations(0,0,nums,target,dp);
    }
};