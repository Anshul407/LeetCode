class Solution {
public:
    vector<int>rank,parent;
    bool factor(int x,int y){
        int mini=min(x,y);
        for(int i=2;i<=mini;i++){
            if(x%i==0&&y%i==0)return 1;
        }
        return 0;
    }
    void abc(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findp(int node){
        if(parent[node]==node)return node;
        return parent[node]=findp(parent[node]);
    }
    void unionbyrank(int u,int v){
        int pu=findp(u);
        int pv=findp(v);
        if(pu==pv)return ;

        if(rank[pu]>rank[pv])parent[pv]=pu;
        else if(rank[pu]<rank[pv])parent[pu]=pv;
        else {
            parent[pu]=pv;
            rank[pv]++;

        }
    }
    int largestComponentSize(vector<int>& nums) {
        int s=0;
        for(auto i:nums)s=max(s,i);
        abc(s);
        for(auto i:nums){
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    unionbyrank(i,j);
                    unionbyrank(i,i/j);
                }
            }
        }
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[findp(nums[i])]++;
        }
        int ans=0;
        for(auto i:mp){
            ans=max(ans,i.second);
        }
        return ans;
    }
};