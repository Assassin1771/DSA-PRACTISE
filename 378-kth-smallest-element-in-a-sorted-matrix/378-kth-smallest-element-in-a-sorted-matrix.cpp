class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(matrix[i][j]);
            }
        }
        
        int result;
        while(k)
        {
            if(k==1)
            {
                result=pq.top();
                break;
            }
            
            pq.pop();
            k--;
        }
        
        return result;
    }
};