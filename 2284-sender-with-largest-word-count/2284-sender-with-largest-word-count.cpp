class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>mp;
        int x=0;
        int maxi=INT_MIN;
        string ans="";
        for(auto j:messages){
            int cnt=1;
            for(auto i:j){
                if(i!=' '){
                    continue;
                }
                cnt++;

            }
            mp[senders[x]]+=cnt;
            x++;
        }
         for (auto& i : mp) {
            if (i.second > maxi || (i.second == maxi && i.first > ans)) {
                maxi = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};