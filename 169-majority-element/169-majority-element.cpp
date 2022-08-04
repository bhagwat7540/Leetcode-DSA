class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele , cnt=0;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(cnt==0) ele = nums[i];
            if(ele == nums[i]) cnt++;
            else cnt--;
        }
        
        return ele;
    }
};