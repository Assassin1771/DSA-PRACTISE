class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> res;
        int first=-1,last=-1;
        
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            
            else if(nums[mid]>target)
                h=mid-1;
            
            else
            {
                if(mid==0 or nums[mid]!=nums[mid-1])
                {
                    first=mid;
                    break;
                }
                
                else
                    h=mid-1;
            }
        }
        
        l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]<target)
                l=mid+1;
            
            else if(nums[mid]>target)
                h=mid-1;
            
            else
            {
                if(mid==n-1 or nums[mid]!=nums[mid+1])
                {
                    last=mid;
                    break;
                }
                
                else
                    l=mid+1;
            }
        }
        
        res.push_back(first);
        res.push_back(last);
        
        return res;
        
        
        
    }
};