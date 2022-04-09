class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto [x,y]:mp)
        {
            pq.push({y,x});
        }
        
        vector<int> res;
        while(k--)
        {
            auto it=pq.top();
            pq.pop();
            
            res.push_back(it.second);
        }
        
        return res;
        
    }
};