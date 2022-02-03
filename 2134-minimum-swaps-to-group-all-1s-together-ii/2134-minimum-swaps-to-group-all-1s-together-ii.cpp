class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        //SLIDING WINDOW
        int n=nums.size();
        int ones=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                ones++;
        }
        
        int res=0;
        for(int i=0;i<ones;i++)
        {
            if(nums[i]==0)
                res++;
        }
        
        int temp=res;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==0 and nums[(i+ones-1)%n]==1)
            {
                temp--;
                res=min(res,temp);
            }
            
            else if(nums[i-1]==1 and nums[(i+ones-1)%n]==0)
            {
                temp++;
                res=min(res,temp);
            }
        }
        
        return res;
        
    }
};