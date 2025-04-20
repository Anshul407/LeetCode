class Solution {
public:
    int solve(string &s,string &t,int i,int j){
        if(i>=s.size())return 1;
        if(j>=t.size())return 0;
        if(s[i]==t[j]){
            return solve(s,t,i+1,j+1);
        }else{
            return solve(s,t,i,j+1);
        }return 0;
    }
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};