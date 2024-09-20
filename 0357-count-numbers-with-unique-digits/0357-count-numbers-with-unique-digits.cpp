class Solution {
public:
    int solve(int n,vector<bool>&vis){
        if(n==0)return 1;
        int tk=0;
        for(int i=0;i<=9;i++){
            if(!vis[i]){
                if(i==0&&n==1)continue;
                vis[i]=1;
                tk+=solve(n-1,vis);
                vis[i]=0;
            }
        }
        return tk;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<bool>vis(10,0);
        int ans=1;
        for(int i=1;i<=n;i++){

            ans+=solve(i,vis);
        }
        return ans;
    }
};