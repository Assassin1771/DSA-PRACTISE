class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            int diff=abs(x-arr[i]);
            
            pq.push({diff,arr[i]});
        }
        
        vector<int> res;
        while(pq.size() and k--)
        {
            int diff=pq.top().first;
            int value=pq.top().second;
            
            res.push_back(value);
            pq.pop();
        }
        
        sort(res.begin(),res.end());
        return res;
        
    }
};