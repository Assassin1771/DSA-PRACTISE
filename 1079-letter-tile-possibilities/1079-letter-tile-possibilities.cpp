class Solution {
public:
    
    set<string> res;
    
    void fun(int ind, string temp, string tiles, vector<int> &vis)
    {
        if(temp.size()>0)
            res.insert(temp);
        
        for(int i=0;i<tiles.size();i++)
        {
            if(vis[i]==0)
            {   
                vis[i]=1;
                temp.push_back(tiles[i]);
                
                fun(i+1,temp,tiles,vis);
                
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        
        string temp="";
        vector<int> vis(tiles.size(),0);
        
        fun(0,temp,tiles,vis);
        
        return res.size();
        
    }
};