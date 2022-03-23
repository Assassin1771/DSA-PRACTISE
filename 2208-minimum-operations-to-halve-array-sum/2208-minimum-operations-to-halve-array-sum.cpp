class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        int n=nums.size();
        
        priority_queue<double> pq;
        
        for(int i=0;i<n;i++)
            pq.push(nums[i]);
        
        double sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        double temp=0;
        int res=0;
        
        while(temp<sum/2)
        {
            double x=pq.top();
            temp+=x/2;
            
            pq.pop();
            pq.push(x/2);
            
            res++;
        }
        
        return res;
        
        
        
    }
};