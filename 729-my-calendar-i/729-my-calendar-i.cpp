//https://leetcode.com/problems/my-calendar-i/discuss/1262664/Easy-Solutions-w-Explanation-and-Diagram-or-Brute-Force-and-Binary-Search-Approach

class MyCalendar {
public:
    
    unordered_map<int,int> mp;
    
    MyCalendar() {
        
    }
    
    bool book(int s1, int e1) {
        
        for(auto [s2,e2]:mp)
        {
            if(!(s1>=e2 or s2>=e1))
                return false;
        }
        
        mp[s1]=e1;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */