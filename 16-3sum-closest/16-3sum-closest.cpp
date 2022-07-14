class Solution {
public:
    
    int res=1e9;
    int ans=0;
    
    void findPair(int ind, vector<int> &nums, int target)
    {
        int low=ind, high=nums.size()-1;
        
        while(low<high)
        {
            // cout<<nums[ind-1]<<" "<<nums[low]<<" "<<nums[high]<<endl;
            
            int curr=nums[ind-1]+nums[low]+nums[high];
            
            if(abs(target-curr)<res)
            {
                res=abs(target-curr);
                ans=curr;
            }
            
            if(curr<target)
                low++;
            
            else
                high--;
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            int temp=curr;
            
            findPair(i+1,nums,target);
        }
        
        return ans;
        
    }
};