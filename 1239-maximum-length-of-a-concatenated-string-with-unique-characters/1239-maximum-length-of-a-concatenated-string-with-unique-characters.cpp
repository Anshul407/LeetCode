class Solution {
public:
    int solve(vector<string>arr,int i,vector<vector<int>>&dp,string ans){
        if(i>=arr.size())return 0;
        
        string temp=ans;
        temp+=arr[i];
        unordered_map<int,int>mp;
        for(auto i:temp){
            mp[i]++;
        }
        int f=1;
        for(auto i:mp){
            if(i.second>1){
                f=0;
                break;
            }
        }

        int tk=0,ntk=0;
        if(f){
            tk=arr[i].size()+solve(arr,i+1,dp,temp);
        }
        ntk=solve(arr,i+1,dp,ans);

        return max(tk,ntk);
    }
    int maxLength(vector<string>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(1001,-1));
        string ans="";
        return solve(arr,0,dp,ans);
    }
};