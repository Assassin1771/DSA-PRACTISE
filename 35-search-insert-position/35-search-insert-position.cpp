class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        auto x=lower_bound(begin(nums),end(nums),target);
        int it=x-begin(nums);
        
        if(x==end(nums))
            return (upper_bound(begin(nums),end(nums),target)-begin(nums));
        
        return it;
            
        
    }
};