class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(k==0)
            return nums[0];
        
        if(k%2 and n==1)
            return -1;
        
        if(k%2==0 and n==1)
            return 0;
        
        if(k>n )
            return *max_element(nums.begin(),nums.end());
        
        if(k==1)
            return nums[1];
        
        priority_queue<int> pq;
        
        int temp=0,i=0;
        for(i=0;i<n;i++)
        {
            if(temp<k-1)
            {
                pq.push(nums[i]);
                temp++;
            }
            
            else
                break;
        }
        
        return max(nums[i+1],pq.top());
        
    }
};