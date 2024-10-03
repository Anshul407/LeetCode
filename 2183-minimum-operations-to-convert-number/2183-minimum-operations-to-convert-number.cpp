class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int,int>>q;
        vector<int>vis(1001,0);
        q.push({start,0});
        while(!q.empty()){
            auto cur=q.front().first;
            auto d=q.front().second;
            q.pop();
             if(cur==goal)return d;
            if(cur>1000||cur<0||vis[cur])continue;
            vis[cur]=1;
            for(auto i:nums){
               
                    q.push({cur + i, d + 1});
                
                    q.push({cur - i, d + 1});
                    q.push({cur ^ i, d + 1});
            }
        }
        return -1;
    }
};