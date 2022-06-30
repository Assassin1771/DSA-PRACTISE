//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/2215732/C%2B%2B-oror-3-Approaches-oror-Full-Explanation

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int middle=0;
        if(n%2)
            middle=nums[n/2];
        
        else
            middle=(nums[n/2-1]+nums[n/2])/2;
        
        int res=0;
        for(auto i:nums)
            res+=abs(i-middle);
        
        return res;
    }
};