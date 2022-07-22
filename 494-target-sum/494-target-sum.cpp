class Solution {
public:
    
    int totalWays(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(nums[0]==0 and sum==0)
                return 2;
            
            else if(nums[0]==sum or sum==0)
                return 1;
            
            else
                return 0;
        }
        
        if(sum<0)
            return 0;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        int notTake=totalWays(ind-1,sum,nums,dp);
        int take=0;
        
        if(nums[ind]<=sum)
            take=totalWays(ind-1,sum-nums[ind],nums,dp);
        
        return dp[ind][sum]= take+notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalSum=0;
        for(auto i:nums)
            totalSum+=i;
        
        int sum=(totalSum-target)/2;
        
        if(sum<0 or (totalSum-target)%2)
            return 0;
        
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return totalWays(n-1,sum,nums,dp);
        
    }
};