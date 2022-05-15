class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n=nums.size();
        int res=0;
        
        vector<long long> prefix_sum(n);
        prefix_sum[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        
        long long last_val=prefix_sum[n-1];
        for(int i=0;i<n-1;i++)
        {
            long long curr_sum=prefix_sum[i];
            
            if(last_val-curr_sum<=curr_sum)
                res++;
        }
        
        return res;
        
    }
};