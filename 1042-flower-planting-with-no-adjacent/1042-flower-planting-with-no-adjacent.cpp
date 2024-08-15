class Solution {
public:
    void dfs(int i,vector<int>&ans,map<int,vector<int>>&mp){
       vector<bool> used(5, false); // Track used colors (1 to 4)

        // Mark the colors used by the neighboring gardens
        for (auto v : mp[i]) {
            if (ans[v]) {
                used[ans[v]] = true;
            }
        }

        // Assign the first available color
        for (int c = 1; c <= 4; ++c) {
            if (!used[c]) {
                ans[i] = c;
                break;
            }
        }

        // Recursively color the adjacent nodes
        for (auto v : mp[i]) {
            if (!ans[v]) {
                dfs(v, ans, mp);
            }
        }
        
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int,vector<int>>mp;
        for(auto i:paths){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(ans[i]==0){
                
                dfs(i,ans,mp);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};