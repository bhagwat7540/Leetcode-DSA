class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k1) {
        int n = matrix.size();
//         vector<int> a(n*n);
//         int k=0;
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<n ; j++){
//                 a[k] = matrix[i][j];
//                 k++;
//             }
//         }
        
//         sort(a.begin() , a.end());
        
        // tc-o(n2 + n2logn)
        //sc- o(n2)
        
//         return a[k1-1];
        int l = -1e9;
        int r = 1e9;
        int ans;
        
        while(l<=r){
            long long mid = l + (r-l)/2;
            int cnt=0;
            for(int i=0 ; i<n ; i++){
                int ind = upper_bound(matrix[i].begin() , matrix[i].end() , mid) - 
                          matrix[i].begin();
                    
                cnt += ind;    
            }
            
            if(cnt >= k1){
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        
        return ans;
        
        //tc-o(n * logN * logn) better than n2
        // sc-o(1)
    }
};