class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int rem=k;
        for(int i=0;i<s.length();i+=rem){
            int cur=0;
            for(int k=i;k<i+rem;k++){
                cout<<s[k]<<" ";
                cur+=(s[k]-'a');
            }
            cur%=26;
            ans+=(cur+'a');
            cout<<endl;
        }
        return ans;

    }
};