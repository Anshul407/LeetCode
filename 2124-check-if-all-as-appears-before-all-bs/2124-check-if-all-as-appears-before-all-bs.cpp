class Solution {
public:
    bool checkString(string s) {
        int flag=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='a'){
                flag=1;
            }
            if(s[i]=='b'&&flag)return 0;
        }
        return 1;
    }
};