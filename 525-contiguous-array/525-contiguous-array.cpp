class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxx=0 , ans=0;
        map<int , int> mp;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0) ans -= 1;
            else ans += 1;
            
            if(ans == 0) maxx = i+1;
            
            if(mp.find(ans) != mp.end()) maxx = max(maxx , i-mp[ans]);
            else mp[ans]=i;
            
        }
        
        return maxx;
    }
};