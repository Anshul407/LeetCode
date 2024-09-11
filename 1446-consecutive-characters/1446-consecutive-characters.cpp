class Solution {
public:
    int maxPower(string s) {
        
        int ans=0;
        int cur=0;
        char p=s[0];
        int i=0;
        while(i<s.length()){
            if(p=='.'||p==s[i]){
                
                cur++;
                i++;
                continue;
            }
            p=s[i];
            ans=max(ans,cur);
            cur=1;
            i++;


        }
        return max(ans,cur);
    }
};