class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
//         sort(nums.begin() , nums.end());
//         int cnt=1;
//         int ans=1;
        
//         for(int i=1 ; i<nums.size() ; i++){
//             if(nums[i]==nums[i-1]) continue;
//             else if(nums[i] == nums[i-1]+1){
//                 cnt++;
//                 ans = max(ans , cnt);
//             }
//             else cnt=1;
//         }
        
//         return ans;
        
        set<int> s;
        int ans=0;
        for(int i : nums) s.insert(i);
        
        for(int i : nums){
            if(s.find(i-1)==s.end()){
                int curr = i;
                int cnt=1;
                
                while(s.find(curr+1) != s.end()){
                    curr++;
                    cnt++;
                }
                
                ans = max(ans , cnt);
            }
        }
        
        return ans;
    }
};