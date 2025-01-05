class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if(s.size()==1)return 1;
        int i=0,j=1;
        int flag=0;
        int ans=0;
        while(j<s.size()){
            if(s[j-1]==s[j]){
                flag++;
            }
            while(flag>1){
                if(s[i]==s[i+1]){
                    flag--;
                }
                i++;
            }
            if(flag<=1)ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};