class Solution {
public:
    bool isABCD(string s,int n){
        if(s[n-1]=='B'&&s[n-2]=='A')return 1;
         if(s[n-1]=='D'&&s[n-2]=='C')return 1;
         return 0;
    }
    int minLength(string s) {
        string ans="";
        for(auto i:s){
            ans+=i;

            if(ans.length()>=2){
                if(isABCD(ans,ans.length())){
                    ans.pop_back();
                    ans.pop_back();
                }
            }
        }
        return ans.length();
    }
};