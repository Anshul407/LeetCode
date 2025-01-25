class Solution {
public:
     vector<int>rank,parent;
    void abc(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findp(int node){
        if(node==parent[node])return node;
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        abc(nums.size());
        vector<pair<int,int>>h;
        for(int i=0;i<nums.size();i++){
            h.push_back({nums[i],i});
        }
        sort(h.begin(),h.end());
        for(int i=1;i<nums.size();i++){
             if(abs(h[i].first-h[i-1].first)<=limit)unionbyrank(h[i].second,h[i-1].second);
        }
        vector<int>x=nums;
        unordered_map<int, priority_queue<int>>mp;
        for(int i=0;i<nums.size();i++){
           mp[findp(i)].push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            auto p=findp(i);
            nums[i]=mp[p].top();
            mp[p].pop();
        }
        return nums;

    }
};