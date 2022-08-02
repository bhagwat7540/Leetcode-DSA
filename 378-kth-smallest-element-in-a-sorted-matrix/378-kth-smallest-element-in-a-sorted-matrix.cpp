class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k1) {
        int n = matrix.size();
        vector<int> a(n*n);
        int k=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                a[k] = matrix[i][j];
                k++;
            }
        }
        
        sort(a.begin() , a.end());
        
        return a[k1-1];
    }
};