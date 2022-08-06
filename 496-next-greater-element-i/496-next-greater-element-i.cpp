class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> mp;
        
        for(int i : nums2){
            
            while(!s.empty() && s.top() < i){
                mp[s.top()]=i;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            mp[s.top()] = -1;
            s.pop();
        }
        
        vector<int> ans;
        for(int i : nums1){
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};