class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int x=s.length()-1;
        int flag=0;
        for(int i=x;i>=0;i--){
            if(s[i]==' '&&flag==1)break;
            if(s[i]!=' '){
                  cnt++;
                  flag=1;
            }
        }
       
        return cnt;
        
    }
};