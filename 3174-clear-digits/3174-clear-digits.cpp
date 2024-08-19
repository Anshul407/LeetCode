class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto i:s){
            if(!isdigit(i)){
                ans+=i;
            }else{
                if(!ans.empty())ans.pop_back();
            }
        }
        return ans;
    }
};