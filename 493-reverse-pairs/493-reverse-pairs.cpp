class Solution {
public:
    
    int merge(vector<int>& a , int s , int m , int e){
        vector<long long> temp;
        int i=s , j=m+1 , k=s;
        long long ans=0;
        
        while(i<=m){
            while(j<=e && a[i] > 2ll*a[j]) j++;
            ans+=j-(m+1);
            i++;
        }
        
        i=s , j=m+1;
        while(i<=m && j<=e){
            if(a[i]<=a[j]) temp.push_back(a[i++]);
            else{
                temp.push_back(a[j++]);
            }
        }
    
        while(i<=m) temp.push_back(a[i++]);
        while(j<=e) temp.push_back(a[j++]);
    
        for(int i=s ; i<=e ; i++) a[i] = temp[i-s];
    
        return ans;
    }
    
    int mergeSort(vector<int>& nums , int s , int e){
        if(s>=e) return 0;
        
        int ans=0;
        int mid = s+(e-s)/2;
        ans+=mergeSort(nums , s , mid);
        ans+=mergeSort(nums , mid+1 , e);
        
        ans+=merge(nums , s , mid , e);
        
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        return mergeSort(nums , 0 , n-1);
    }
};