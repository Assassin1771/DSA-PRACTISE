class Solution {
public:
    
    bool findSubsets(vector<int> &nums, vector<int> &vis, int target, int k, int curr_sum, int ind)
    {
        int n=nums.size();
        
        if(k==1)
            return true;
        
        if(ind>=n)
            return false;
        
        if(curr_sum==target)
            return findSubsets(nums,vis,target,k-1,0,0);
        
        for(int i=ind;i<n;i++)
        {
            if(vis[i]==1 or curr_sum+nums[i]>target)
                continue;
            
            if(vis[i]==0)
            {
                vis[i]=1;
            
                if(findSubsets(nums,vis,target,k,curr_sum+nums[i],i+1))
                return true;
            
                vis[i]=0;    
            }
            
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int sum=0;
        for(auto i:nums)
            sum+=i;
        
        for(auto i:nums)
        {
            if(i>sum/k)
                return false;
        }
        
        if(n<k or sum%k)
            return false;
        
        vector<int> vis(n,0);
        
        sort(nums.begin(),nums.end());
        
        return findSubsets(nums,vis,sum/k,k,0,0);
        
    }
};