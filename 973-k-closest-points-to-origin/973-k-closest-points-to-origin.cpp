#define datatype pair<double,pair<int,int>>

class Solution {
public:
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int rows=points.size();
        int cols=2;
        
        priority_queue<datatype,vector<datatype>,greater<datatype>> pq;
        
        for(int i=0;i<rows;i++)
        {
            int first=points[i][0];
            int second=points[i][1];
            
            // cout<<first<<" "<<second<<endl;
            int firstTerm=pow(first,2);
            // cout<<"f"<<firstTerm<<endl;
            
            int secondTerm=pow(second,2);
            // cout<<"s"<<secondTerm<<endl;
            
            double dist=sqrt(firstTerm+secondTerm);
            
            // cout<<dist<<endl;
            pq.push({dist,{first,second}});
        }
        
        vector<vector<int>> res;
        while(k--)
        {
            auto it=pq.top();
            pq.pop();
            
            int firstIndex=it.second.first;
            int secondIndex=it.second.second;
            
            vector<int> temp;
            temp.push_back(firstIndex);
            temp.push_back(secondIndex);
            
            res.push_back(temp);
                                
        }
        
        return res;
            
            
        
        
        
    }
};