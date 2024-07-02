class Solution {
public:
int find(int x,vector<int>&p){
        if(x==p[x])return x;

        return p[x]=find(p[x],p);
    }
    void unionn(int x,int y,vector<int>&p,vector<int>&r){
        int xp=find(x,p);
        int yp=find(y,p);
        if (xp == yp) 
            return;
        if(r[xp]>r[yp]){
            p[yp]=xp;
        }
        else if(r[xp]<r[yp]){
            p[xp]=yp;
        }else{
            p[xp]=yp;
            r[yp]+=1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
        vector<int>rank(n,0);
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            unionn(x,y,parent,rank);
            
        }
        // unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            
            int papaji=find(i,parent);
            // cout<<parent[i];
            // mp[papaji]++;
        }
        cout<<" na  ";
        // long long res=0;
        // long long nn=n;
        // for(auto i:mp){
        //     long long size=i.second;
        //     res+=size*(nn-size);
        //     nn-=size;
        // }
        long long ans=0;
        for(int i=0;i<n;i++){
            cout<<parent[i];
            for(int j=0;j<n;j++){
                if(parent[i]!=parent[j])ans++;
            }
        }
        return ans/2;
    }
};