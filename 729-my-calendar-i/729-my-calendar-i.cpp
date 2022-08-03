class MyCalendar {
public:
    
    map<int,int> mp;
    
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        
        for(auto x : mp){
            int s = x.first , e = x.second;
            
            if(start<e && end>s) return false;
        }
        
        mp[start] = end;
        return true;
        
        // for(int i=start ; i<end ; i++) vis[i]=1;
        // return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */