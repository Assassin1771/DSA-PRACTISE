class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        int ind1=-1,ind2=-1;
        
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=temp[i])
            {
                if(ind1==-1)
                    ind1=i;
                
                else
                    ind2=i;
            }
        }
        
        if(ind1==-1 or ind2==-1)
            return 0;
        
        return abs(ind2-ind1+1);
        
    }
};