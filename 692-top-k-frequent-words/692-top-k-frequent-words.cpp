class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        
        map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            string s=words[i]; 
            mp[s]++;
        }
        
        map<int, vector<string>> mp1;
        
        for(auto [x,y]:mp)
        {
            mp1[y].push_back(x);
        }
        
        for(auto [x,y]:mp1)
            sort(y.begin(),y.end());
        
        priority_queue<pair<int, vector<string>>> pq;
        
        for(auto [x,y]:mp1)
            pq.push({x,y});
        
        vector<string> res;
        while(k)
        {
            auto it=pq.top();
            pq.pop();
            
            vector<string> temp=it.second;
            
            for(auto i:temp)
            {
                if(k>0)
                {
                    res.push_back(i);
                    k--;
                }
                
                else
                    break;
            }
        }
        
        return res;
        
        
        
    }
};