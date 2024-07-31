class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long x=0;
        vector<int>ans;
        for(auto i:word){
            x=(x*10+(i-'0'))%m;
            if(x%m==0)ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};