// https://leetcode.com/problems/merge-intervals/discuss/482195/C%2B%2B-9-lines-99-Run-Time-Easy-to-understand-solution

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        
        res.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            int m=res.size();
            
            if(res[m-1][1]>=nums[i][0])
                res[m-1][1]=max(res[m-1][1],nums[i][1]);
            
            else
                res.push_back(nums[i]);
        }
        
        return res;
        
    }
};