class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans=0;
        for(int i=0;i<citations.size();i++){
            if(citations.size()-i<=citations[i])ans=max(ans,(int)citations.size()-i);
        }
        return ans;
    }
};