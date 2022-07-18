class Bank {
public:
    
    vector<long long> v;
    long long n;
    
    Bank(vector<long long>& balance) {
        
        v=balance;
        n=v.size();   
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(account1-1>=n or account2-1>=n)
            return false;
        
        long long x=v[account1-1];
        long long y=v[account2-1];
        
        if(x<money)
            return false;
        
        v[account1-1]-=money;
        v[account2-1]+=money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        
        if(account-1>=n)
            return false;
        
        v[account-1]+=money;
        return true;
        
    }
    
    bool withdraw(int account, long long money) {
        
        if(account-1>=n)
            return false;
        
        long long x=v[account-1];
        
        if(x>=money)
        {
            v[account-1]-=money;
            return true;
        }
        
        else
            return false;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */