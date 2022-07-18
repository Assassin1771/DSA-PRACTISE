//https://leetcode.com/problems/best-sightseeing-pair/discuss/1468367/Code-walk-through-O(n)-time-%2B-O(1)-space

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n=values.size();
        
        int i=0,j=1;

        int maxLeft=values[i]+i;
        int res=0;
        
        while(j<n)
        {
            res=max(res,maxLeft+values[j]-j);
            maxLeft=max(maxLeft,values[j]+j);
            
            j++;
        }
        
        return res;
    }
};