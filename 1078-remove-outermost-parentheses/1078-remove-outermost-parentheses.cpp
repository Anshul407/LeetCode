class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int o=0;
        for(auto i:s){
            if(i=='('){
                if(o>0)
                ans+=i;o++;}
            
           else if(i==')'){
            o--;
            if(o>0)ans+=i;
           }
            
        }
        return ans;
    }
};