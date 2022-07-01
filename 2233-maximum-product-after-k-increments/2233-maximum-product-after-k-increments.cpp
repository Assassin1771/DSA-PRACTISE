class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n==1)
            return nums[0]+k;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto i:nums)
            pq.push(i);
        
        while(k)
        {
            int x=pq.top();
            pq.pop();
            
            int y=pq.top();
            pq.pop();
            
            int diff=(y-x);
            
            if(diff+1<=k)
            {
                x+=diff+1;
                k-=(diff+1);
            }
            
            else
            {
                x+=k;
                k-=k;
            }
            
            pq.push(x);
            pq.push(y);
        }
        
        long long res=1;
        while(pq.size())
        {
            res*=pq.top();
            res=res%(long long)(1e9+7);
            
            pq.pop();
        }
        
        return res;
        
    }
};