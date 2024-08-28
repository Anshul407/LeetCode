class Solution {
public:
    bool check(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            if(check(i))return i;
        }
        return "";
    }
    
};