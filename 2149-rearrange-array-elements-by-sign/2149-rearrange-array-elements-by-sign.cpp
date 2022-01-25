class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> neg;
        vector<int> pos;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                neg.push_back(nums[i]);
            
            else
                pos.push_back(nums[i]);
        }
        
        vector<int> res;
        
        for(int i=0;i<pos.size();i++)
        {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        
        return res;
        
    }
};