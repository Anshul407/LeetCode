class Solution {
public:
    void solve(int i,vector<int>num,vector<int>temp,int n,int k,vector<vector<int>>&ans){
        if(i==num.size()){
            if(temp.size()==k){
            int sum=0;
            for(auto ii:temp)sum+=ii;
            if(sum==n)ans.push_back(temp);
           
        }
            return ;}
        if(temp.size()==k){
            int sum=0;
            for(auto ii:temp)sum+=ii;
            if(sum==n)ans.push_back(temp);
            return ;
        }
        solve(i+1,num,temp,n,k,ans);
        int sum=0;
        for(auto ii:temp)sum+=ii;
        
        if(temp.empty()||sum<n){
            temp.push_back(num[i]);
            solve(i+1,num,temp,n,k,ans);
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>num;
        for(int i=1;i<=9;i++){
            num.push_back(i);
        }
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,num,temp,n,k,ans);
        return ans;
    }
};