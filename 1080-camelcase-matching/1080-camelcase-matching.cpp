class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(auto i:queries){
            auto cur=i;
            int k=0;
            auto f=true;
            int j=0;
            while(j<cur.size()){
                while(j<cur.size()&&k<pattern.size()&&cur[j]==pattern[k]){
                    j++;
                    k++;
                }
                if(isupper(cur[j])&&cur[j]!=pattern[k]){
                    f=false;
                    break;
                }
                j++;
            }
            if(k>=pattern.size()&&f)ans.push_back(f);
            else ans.push_back(false);
        }
        return ans;
    }
};