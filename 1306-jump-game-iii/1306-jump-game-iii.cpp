class Solution {
public:
    
    bool check(int ind, vector<int> &nums, vector<int> &vis)
    {
        // cout<<ind<<endl;
        int n=nums.size();
        if(ind<0 or ind>=n)
            return false;
        
        if(nums[ind]==0)
            return true;
        
        if(vis[ind]!=0)
            return false;
        
        vis[ind]=true;
        
        bool l=check(ind+nums[ind],nums,vis);
        bool r=check(ind-nums[ind],nums,vis);
        
        vis[ind]=false;
        
        return max(l,r);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        vector<int> dp(n+1,0);
        return check(start,arr,dp);
        
    }
};