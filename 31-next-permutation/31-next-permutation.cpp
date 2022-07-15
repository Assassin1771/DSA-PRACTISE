class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        int start=0;
        for(start=n-2;start>=0;start--)
        {
            if(nums[start]<nums[start+1])
            {
                break;
            }
        }
        
        if(start<0)
            sort(nums.begin(),nums.end());
        
        else
        {
            int end=0;
            for(end=n-1;end>start;end--)
            {
                if(nums[end]>nums[start])
                {
                    break;
                }
            }
            
            swap(nums[start],nums[end]);
            
            reverse(nums.begin()+start+1,nums.end());
        }
        
        
    }
};