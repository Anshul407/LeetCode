class Solution {
public:
    // int gcd(int x,int y){
    //     return y==0?x:gcd(y,x%y);
    // }
    // int lcm(long long x,long long y){
    //     return (x / gcd(x, y)) * y;
    // }
    void dfs(int i,unordered_map<int,bool>&vis,unordered_map<int,vector<int>>&mp){
        vis[i]=1;
        for(auto v:mp[i]){
            if(vis[v]==0)dfs(v,vis,mp);
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
        unordered_map<int,vector<int>>mp;
        for(auto i:nums){
            for(int j=2*i;j<=threshold;j+=i){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
        unordered_map<int,bool>vis;
        for(auto i:nums){
            vis[i]=0;
        }
        int ans=0;
        for(auto i:nums){
            if(vis[i]==0){
                ans++;
                dfs(i,vis,mp);
            }
        }
        return ans;
            
    }
};