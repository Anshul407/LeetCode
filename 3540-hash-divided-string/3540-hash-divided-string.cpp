class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int i=0;
        while(i<s.size()){
            int cnt=0;
            int temp=0;
            while(i<s.size()&&cnt<k){
                cnt++;
                temp+=(s[i]-'a');
                i++;
            }
            temp%=26;
            ans.push_back(temp+'a');
        }return ans;
    }
};