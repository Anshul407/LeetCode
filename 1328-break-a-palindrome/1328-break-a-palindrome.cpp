class Solution {
public:
    string breakPalindrome(string p) {
        int n=p.size();
        int flag=0;
        if(n==1){
            return "";
        }
        for(int i=0;i<n/2;i++){
            if(p[i]!='a'){
                flag=1;
                p[i]='a';
                break;
            }
        }
        if(flag)return p;
        else{
            p[n-1]='b';
            return p;
        }
    }
};