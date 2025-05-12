class Solution {
public:
    vector<int>vis;
    void solve(vector<int>&digits,vector<int>&ans,int temp,int cnt){
        if(cnt==3){
            if(temp%2==0)ans.push_back(temp);
            return ;
        }
        for(int i=0;i<digits.size();i++){
            if(vis[i])continue;
            if(cnt==0&&digits[i]==0)continue;
            vis[i]=1;
            solve(digits,ans,temp*10+digits[i],cnt+1);
            vis[i]=0;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        vis.resize(digits.size(),0);
        vector<int>ans;
        solve(digits,ans,0,0);
        set<int>a;
        for(auto i:ans)a.insert(i);
        ans={};
        for(auto i:a)ans.push_back(i);
        return ans;
    }
};