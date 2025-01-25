class Solution {
public:
    int solve(string &s,int i,int j){
        if(i>=j)return 1;
        if(isalnum(s[i])&&isalnum(s[j])){
            if(tolower(s[i])!=tolower(s[j]))return 0;
            return solve(s,i+1,j-1);
        }
        if(!isalnum(s[i])&&!isalnum(s[j]))return solve(s,i+1,j-1);
        if(!isalnum(s[i]))return solve(s,i+1,j);
        return solve(s,i,j-1);
    }
    bool isPalindrome(string s) {
        return solve(s,0,s.size()-1);
    }
};