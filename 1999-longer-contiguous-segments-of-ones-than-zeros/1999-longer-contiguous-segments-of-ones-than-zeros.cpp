class Solution {
public:
    bool checkZeroOnes(string s) {
        int o=0,z=0;
        int az=0,ao=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                o++;
                z=0;
            }else{
                z++;
                o=0;
            }
            ao=max(ao,o);
            az=max(az,z);
        }
        return ao>az;
    }
};