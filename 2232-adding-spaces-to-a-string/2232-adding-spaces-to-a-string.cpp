class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        int k=0;
        for(auto i:s){
            if(j<spaces.size()&&spaces[j]==k){j++;ans+=" ";}
            ans+=i;
            k++;
        }
        return ans;
    }
};