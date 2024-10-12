class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0;
        for(auto &i:items){
            if((ruleKey == "type"&&i[0]==ruleValue)||(ruleKey == "color"&&i[1]==ruleValue)||(ruleKey == "name"&&i[2]==ruleValue))ans++;
        }
        return ans;
    }
};