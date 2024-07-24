class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>>mp;
        int cnt=0;
        string temp="";
        for(auto i:text){
            if(i!=' '){
                i=tolower(i);
                temp+=i;
                cnt++;
                continue;
            } else{
                if(cnt){
                    mp[cnt].push_back(temp);
                    cnt=0;
                    temp="";
                }
            }
        }
        if(cnt){
             mp[cnt].push_back(temp);
        }
        string ans="";
        for(auto i:mp){
            for(auto x:i.second){
                ans+=x;
                 ans+=" ";
            }
            
        }
        ans.pop_back();
        ans[0]=toupper(ans[0]);
        return ans;
    }
};