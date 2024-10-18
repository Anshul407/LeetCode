class Solution {
public:
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void solve(string s,int i,vector<string>&temp,vector<vector<string>>&ans){
        if(i>=s.length()){
            ans.push_back(temp);
            return ;
        }

        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        
        solve(s,0,temp,ans);
        return ans;
    }
};