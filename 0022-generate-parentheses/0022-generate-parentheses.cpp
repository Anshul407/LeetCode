class Solution {
public:
    void mp(int open,int close,string op,vector<string>&v){
        if(open==0&&close==0){
            v.push_back(op);
            return ;
        }
        string op1(op),op2(op),op3(op),op4(op);
        if(open==close&&open!=0){
            op1.push_back('(');
            mp(open-1,close,op1,v);
        }
        else if(open!=0&&close!=0){
             op2.push_back('(');
             mp(open-1,close,op2,v);
             op3.push_back(')');
             mp(open,close-1,op3,v);
        }
        else if(close!=0){
               op4.push_back(')');
               mp(open,close-1,op4,v);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        string op;

        vector<string>ans;
        mp(open,close,op,ans);
        return ans;
    }
};