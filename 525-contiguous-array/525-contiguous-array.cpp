class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0 , cnt=0;
        unordered_map<int , int> mp;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0) ans -= 1;
            else ans += 1;
            
            if(ans == 0) cnt = i+1;
            else if(mp.find(ans) != mp.end()) cnt = max(cnt , i-mp[ans]);
            else mp[ans] = i;
        }
        
        return cnt;
    }
};