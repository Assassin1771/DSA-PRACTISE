class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        int prev1=nums[0],prev2=0,curr=0;
        
        if(n==1)
            return nums[0];
        
        int res1=0,res2=0;
        for(int i=1;i<n-1;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            
            int notPick=prev1;
            
            curr=max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        
        res1=prev1;
        
        prev1=nums[1],prev2=0,curr=0;
        for(int i=2;i<n;i++)
        {
            int pick=nums[i];
            if(i>2)
                pick+=prev2;
            
            int notPick=prev1;
            
            curr=max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        
        res2=prev1;
        
        return max(res1,res2);
    }
};