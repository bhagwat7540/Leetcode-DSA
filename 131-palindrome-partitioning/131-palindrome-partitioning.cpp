class Solution {
public:
    vector<vector<string>> ans;
    
    bool pallindrome(string s){
        int i=0 , j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void f(string s , vector<string>& temp){
        
        if(s.length() == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=1 ; i<=s.length() ; i++){
            string yo = s.substr(0,i);
            if(pallindrome(yo)){
                temp.push_back(yo);
                f(s.substr(i) , temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        f(s , temp);
        return ans;
    }
};