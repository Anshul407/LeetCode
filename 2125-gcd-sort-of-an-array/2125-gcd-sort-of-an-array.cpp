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
    bool gcdSort(vector<int>& nums) {
        abc(100000);
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    unionbyrank(nums[i],j);
                    unionbyrank(nums[i],nums[i]/j);
                }
            }
        }
        vector<int>temp=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(findp(nums[i])!=findp(temp[i]))return 0;
        }
        return 1;

    }
};