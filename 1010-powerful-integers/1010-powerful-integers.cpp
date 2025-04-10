class Solution {
public:
    unordered_map<int,int>mp;
    unordered_map<int,unordered_map<int,int>>dp;
    void solve(int x,int y,int bound,int i,int j,int cur){
        if(cur>bound)return ;
        if(cur<=bound&&cur!=-1)mp[cur]++;
        if(dp.find(i)!=dp.end()&&dp[i].find(j)!=dp[i].end())return ;
        solve(x,y,bound,i+1,j,pow(x,i)+pow(y,j));
        solve(x,y,bound,i,j+1,pow(x,i)+pow(y,j));
        dp[i][j]=1; 
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
         if(x==y&&x==1){
            if(2<=bound)return {2};
         }
         dp.clear();
         if(x==1||y==1){
            int i=0;
            vector<int>ans;
            while(true){
                int cur=pow(max(x,y),i)+1;
                i++;
                if(cur>bound)break;
                ans.push_back(cur);
            }return ans;
         }
        solve(x,y,bound,0,0,-1);
        vector<int>ans;
        for(auto i:mp)ans.push_back(i.first);
        return ans;
    }
};