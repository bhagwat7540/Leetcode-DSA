class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& a , int t , int i , vector<int>& yo){
        if(t==0){
            ans.push_back(yo);
            return;
        }
        if(i == a.size() || t<0) return;
        
        for(int j=i ; j<a.size() ; j++){
            if(j!=i && a[j]==a[j-1]){
                continue;
            }
            
            if(a[j] <= t){
                yo.push_back(a[j]);
                f(a , t-a[j] , j+1 , yo);
                yo.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin() , a.end());
        vector<int> yo;
        f(a , target , 0 , yo);
        
        return ans;
    }
};