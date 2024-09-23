class Solution {
public:
    unordered_map<int,vector<int>>mp;
   

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
       
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            
        }
        vector<int>ind(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            ind[i]=mp[i].size();
            if(ind[i]==1)q.push(i);
        }
       
        while(n>2){
            auto size=q.size();
            n-=size;
            while(size--){
            auto node=q.front();
            q.pop();
            for(auto i:mp[node]){
                ind[i]--;
                if(ind[i]==1)q.push(i);
            }}
        }

        int a=q.front();
        q.pop();
        if(q.empty())return {a};

        return {a,q.front()};
        

        
    }
};