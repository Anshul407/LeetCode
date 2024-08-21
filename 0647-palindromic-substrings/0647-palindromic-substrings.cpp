class Solution {
public:
    bool pal(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    int solve(string s,int i){
        if(i>=s.size())return 0;

        int tk=0;
        for(int j=i;j<s.length();j++){
            if(pal(s,i,j)){
                tk++;  
            }
           
        }

        return tk+solve(s,i+1);
    }
    int countSubstrings(string s) {
        return solve(s,0);
    }
};