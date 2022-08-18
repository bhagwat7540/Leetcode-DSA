class Solution {
public:
    set<vector<int>> s;
    
    void f(int i , vector<int>& a , vector<int>& v){
        
        if(i == a.size()){
            s.insert(v);
            return;
        }
        
        f(i+1 , a , v);
        v.push_back(a[i]);
        f(i+1 , a , v);
        v.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> v;
        f(0 , nums , v);
        
        vector<vector<int>> ans;
        for(auto x : s){
            ans.push_back(x);
        }
        
        return ans;
    }
};