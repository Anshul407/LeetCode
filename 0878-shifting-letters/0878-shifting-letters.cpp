class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int>pf(s.size(),0);
        reverse(shifts.begin(),shifts.end());
        pf[0]=shifts[0]%26;
        for(int i=1;i<shifts.size();i++){
            pf[i]=(pf[i-1]+shifts[i])%26;
        }   
        reverse(pf.begin(),pf.end());
        int j=0;
        for(auto &a:s){
            if(a+pf[j]>'z'){
                a+=pf[j];
                a-=26;
            }else{
                a+=pf[j];
            }
            j++;
        }
        return s;
    }
};