class Solution {
public:
    int solve(string &s,int i,int cnt){
        if(i>=s.length())return cnt==s.length();

        int op1=0,op2=0;
        if(s[i]!='0')
        op1=solve(s,i+1,cnt+1);

        if(i<s.length()-1&&s[i]!='0'){
            string ss=s.substr(i,2);
            int num=stoi(ss);
            if(num<=26)
            op2=solve(s,i+2,cnt+2);
        }
        return op1+op2;

    }
    int numDecodings(string s) {
       return solve(s,0,0);
    }
};