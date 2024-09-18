class Solution {
public:
    void solve(int n,string temp,vector<string>&ans,int cnt){
        if(n==0){
     
            ans.push_back(temp);
            return ;
        }
        if(temp.empty()||temp.back()=='1'){
        temp+="0";
        solve(n-1,temp,ans,cnt);
         temp.pop_back();}
        temp+="1";
        solve(n-1,temp,ans,cnt+1);
        temp.pop_back();

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,"",ans,0);
        return ans;
    }
};