class Solution {
public:
    
    int findKadaneSum(vector<int> &nums)
    {
        int n=nums.size();
        
        int maxEnding=nums[0];
        int res=nums[0];
        
        for(int i=1;i<n;i++)
        {
            maxEnding=max(maxEnding+nums[i],nums[i]);
            res=max(res,maxEnding);
        }
        
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
        
        int kadane_sum=findKadaneSum(nums);
        
        if(kadane_sum<0)
            return kadane_sum;
        
        int circular_sum=0;
        int sum=0;
        
        for(auto i:nums)
            sum+=i;
        
        for(int i=0;i<n;i++)
            nums[i]=-nums[i];
        
        circular_sum=sum+findKadaneSum(nums);
        
        // cout<<kadane_sum<<" "<<circular_sum<<endl;
        
        return max(kadane_sum, circular_sum);
    }
};