class Solution {
public:
    int solve(int n,int cnt,vector<int>&vis){
        if(cnt==n){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(i%(cnt+1)==0||(cnt+1)%i==0)){
                vis[i]=1;
                ans+=solve(n,cnt+1,vis);
                vis[i]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        return solve(n,0,vis);
    }
};