class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> res;
        if(n==0)
            return res;
        
        multiset<int,greater<int>> st;
        
        for(int i=0;i<k;i++)
            st.insert(nums[i]);
        
        for(int i=1;i<n-k+1;i++)
        {   
            for(auto j:st)
            {
                res.push_back(j);
                break;
            }
            
            st.erase(st.find(nums[i-1]));
            st.insert(nums[i+k-1]);
        }
        
        for(auto j:st)
        {
            res.push_back(j);
            break;
        }
        
        return res;
    }
};