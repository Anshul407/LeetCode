class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int op=0;
        for(auto i:s){
            if(i=='('){
                if(op>0)ans+='(';
                op++;
            }else if(i==')'){
                op--;
                if(op>0)ans+=')';
                
            }
        }
        return ans;
    }
};