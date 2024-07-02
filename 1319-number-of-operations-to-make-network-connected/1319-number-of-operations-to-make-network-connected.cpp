class Solution {
public:
    int find(int x,vector<int>&p){
        if(x==p[x])return x;

        return p[x]=find(p[x],p);
    }
    void unionn(int x,int y,vector<int>&p,vector<int>&r){
        int xp=find(x,p);
        int yp=find(y,p);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
        vector<int>rank(n,0);
        int cnt=0;
        vector<int>vis(n,0);
        for(auto it:connections){
            
            int x=it[0];
            int y=it[1];
            vis[x]=1;
            vis[y]=1;
            int parent_x=find(x,parent);
            int parent_y=find(y,parent);

            if(parent_x==parent_y)continue;
            else{
                cnt++;
                unionn(parent_x,parent_y,parent,rank);
            }
        }
        // int ntcntcted=0;
        // for(auto i:vis){
        //     if(i==0)ntcntcted++;
        // }
        // if(ntcntcted>cnt)return -1;

        // if(cnt>ntcntcted)return ntcntcted;
        // return cnt;

        return n-cnt-1;
        

    }
};