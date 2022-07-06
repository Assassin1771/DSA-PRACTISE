class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> count(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                
                else if(nums[i]>nums[j] and dp[j]+1==dp[i])
                    count[i]+=count[j];
            }
        }
        
        int target=*max_element(dp.begin(),dp.end());
        int numOfLIS = 0;
        
        for(int i=0;i<n;i++){
            if(dp[i]==target)
                numOfLIS += count[i];
        }
            
        return numOfLIS;        
    }
};