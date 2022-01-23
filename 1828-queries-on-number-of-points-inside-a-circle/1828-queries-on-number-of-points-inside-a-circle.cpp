class Solution {
public:
    
    bool check(int x,int y,int z,int a,int b)
    {
        int temp=pow(abs(x-a),2)+pow(abs(y-b),2);
        
        if(sqrt(temp)<=z)
            return true;
        
        return false;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        int a=points.size();
        int b=2;
        
        int c=queries.size();
        int d=3;
        
        vector<int> res;
        int count=0;
        
        for(int i=0;i<c;i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            int z=queries[i][2];
            
            for(int j=0;j<a;j++)
            {
                if(check(x,y,z,points[j][0],points[j][1]))
                    count++;
            }
                                      
                res.push_back(count);
                count=0;
        }
        
        return res;
        
    }
};