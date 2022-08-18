class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    
    void f(int i , vector<int>& a , vector<int>& v){
        
        ans.push_back(v);
        
        for(int j=i ; j<a.size() ; j++){
            if(j == i || a[j] != a[j-1]){
                v.push_back(a[j]);
                f(j+1 , a , v);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> v;
        f(0 , nums , v);
        
        // vector<vector<int>> ans;
        // for(auto x : s){
        //     ans.push_back(x);
        // }
        
        return ans;
    }
};