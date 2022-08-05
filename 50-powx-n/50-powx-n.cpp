class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans=1;
        
        if(nn<0) nn = (-1)*nn;
        
        while(nn){
            if(nn%2==0) x = x*x , nn=nn/2;
            else ans*=x , nn--;
        }
        
        if(n<0) return 1/ans;
        return ans;
    }
};