class Solution {
public:
    bool isPrefixAndSuffix(string &a,string &b){
        if(a==b)return 1;
        if(a.size()>b.size())return 0;
        auto cond1=a==b.substr(0,a.size());
        auto cond2=a==b.substr(b.size()-a.size(),a.size());
        return cond1&&cond2;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++)
            {
                if(i!=j){
                    if(isPrefixAndSuffix(words[i],words[j]))cnt++;
                }
            }
        }
        return cnt;
    }
};