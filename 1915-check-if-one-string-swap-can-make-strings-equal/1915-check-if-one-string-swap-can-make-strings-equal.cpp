class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        char a,b;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(cnt==0){a=s1[i];b=s2[i];}
                else if(s2[i]!=a||s1[i]!=b)return 0;
                cnt++;

            }
        }
        return cnt==0||cnt==2;

    }
};